#pragma once

#include <iostream>
#include <queue>
#include <pthread.h>

using namespace std;

typedef void *(*Handler_t)(void *args);

class Task{
    private:
        int sock;
        Handler_t h;
    public:
        Task(int _sock = -1){
        }
        void SetTask(int _sock, Handler_t handler){
            h = handler;
            sock = _sock;
        }
        void Run(){
            h((void*)&sock);
        }
        ~Task(){
        }
};

class ThreadPool{
    private:
        int num;
        queue<Task> q; //消费场所
        pthread_mutex_t lock;
        pthread_cond_t cond;
    public:
        ThreadPool(int _num = 5):num(_num){
            pthread_mutex_init(&lock,nullptr);
            pthread_cond_init(&cond, nullptr);
        }
        void LockQueue(){
            pthread_mutex_lock(&lock);
        }
        void UnlockQueue(){
            pthread_mutex_unlock(&lock);
        }
        void WakeupThread(){
            pthread_cond_signal(&cond);
        }
        void PushTask(Task t){
            LockQueue();
            q.push(t);
            UnlockQueue();
            WakeupThread();
        }
        void ThreadWait(){
            pthread_cond_wait(&cond, &lock);
        }
        bool IsQueueEmpty(){
            return q.empty();
        }
        Task PopTask(){
            Task t = q.front();
            q.pop();

            return t;
        }
        static void *Routine(void*args){

            ThreadPool *tp = (ThreadPool*)args;

            while(true){
                tp->LockQueue();
                //从任务队列中那任务
                while(tp->IsQueueEmpty()){
                    //如果任务队列没有任务，就要将当前线程休眠
                    //当任务到来的时候，唤醒线程
                    tp->ThreadWait();
                }
                //处理任务
                Task t = tp->PopTask();
                tp->UnlockQueue();
                t.Run();
            }
        }
        void InitThreadPool(){
            pthread_t tid;
            for(auto i = 0; i < num; i++){
                pthread_create(&tid, nullptr, Routine, this);
                pthread_detach(tid);
            }
        }

        ~ThreadPool(){
            pthread_mutex_destroy(&lock);
            pthread_cond_destroy(&cond);
        }
};


















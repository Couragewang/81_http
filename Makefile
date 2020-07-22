.PHONY:all
all:http_server testCgi

http_server:main.cc
	g++ -o $@ $^ -std=c++11 -lpthread

testCgi:testCgi.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f http_server testCgi

.PHONY:output
output:
	mv testCgi ./wwwroot/cgi

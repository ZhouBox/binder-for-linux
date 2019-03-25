all: testservice testserviceclient

testservice: main.cpp
	g++ -std=c++11 -o $@ -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 $< Itestservice.cpp Testservice.cpp -lbinder -lpthread

testserviceclient: testclient.cpp
	g++ -std=c++11 -o $@ -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 $< Itestservice.cpp -lbinder -lpthread

clean:
	rm -f testservice testserviceclient
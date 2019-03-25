all: testservice testserviceclient

testservice: main.cpp
	g++ -std=c++11 -o $@ -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 $< Itestservice.cpp Testservice.cpp -lpthread -lbinder

testserviceclient: testclient.cpp
	g++ -std=c++11 -o $@ -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 $< Itestservice.cpp -lpthread -lbinder

clean:
	rm -f testservice testserviceclient
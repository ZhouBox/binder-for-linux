all: gcodeparserservice gcodeparserclient

gcodeparserservice: gcodeparser_service_main.cpp
	g++ -std=c++11 -O3 -o $@ -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 $< IGCodeParserClient.cpp IGCodeParser.cpp IGCodeParserService.cpp GCodeParserService.cpp -lbinder -lpthread

gcodeparserclient: gcodeparser_client_main.cpp
	g++ -std=c++11 -O3 -o $@ -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 $< GCodeParserClient.cpp IGCodeParserClient.cpp IGCodeParser.cpp IGCodeParserService.cpp -lbinder -lpthread

clean:
	rm -f gcodeparserservice gcodeparserclient
make:
	gcc src/main.c -o player `pkg-config --cflags --libs gstreamer-1.0`


clean:
	rm -rf ./player

 

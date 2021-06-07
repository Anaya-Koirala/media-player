make:src/*
	gcc src/main.c src/play_demo.c src/play_video.c -o player `pkg-config --cflags --libs gstreamer-1.0`  
clean:
	rm -rf ./player

 

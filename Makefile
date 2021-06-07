cc = clang

make:src/*
	$(cc) src/main.c src/play_demo.c src/play_video.c src/gui.c -o player `pkg-config --cflags --libs gstreamer-1.0`  
clean:
	rm -rf ./player

 

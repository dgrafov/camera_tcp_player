obj_dir = ./obj
lib_dir = ./lib
source_dirs = ./ debug tinyxml2
search_cpp_wildcards = $(addsuffix /*.cpp, $(source_dirs)) 
cpp_obj = $(addprefix $(obj_dir)/, $(notdir $(patsubst %.cpp, $(obj_dir)/%.o, $(wildcard $(search_cpp_wildcards)))))
cflags = `pkg-config --cflags glib-2.0 gstreamer-0.10`
cflags += -std=c++0x
lflags = `pkg-config --libs glib-2.0 gstreamer-0.10`

create_obj_dir := $(shell mkdir -p obj)

all: player

player: $(c_obj) $(cpp_obj)
	g++ $^ -o $@ -L$(lib_dir) $(lflags)

VPATH := $(source_dirs)	  

$(obj_dir)/%.o: %.cpp
	gcc -c -MD $(addprefix -I, $(source_dirs)) $(cflags) -o $@ $<

include $(wildcard $(obj_dir)/*.d) 

clean: 
	rm -f $(obj_dir)/*.o $(obj_dir)/*.d ./player

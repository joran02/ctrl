

include ./makefile.rule

INC_PATH += -I./include
INC_PATH += -I../common
INC_PATH += -I./
INC_PATH += -I../../common/include/dms_api_include



CFLAGS += -DHI_ACODEC_TYPE_NVP6124 -DHI_ACODEC_TYPE_HDMI 
CFLAGS +=   $(INC_PATH) 
CFLAGS +=  $(INC_FLAGS)


LIBDIR=$(PROJECT_DIR)/common/lib

SRCS    :=  $(wildcard *.cpp)
OBJS    :=  $(SRCS:%.cpp=%.o)

MY_OBJS := libgCtrl.o

STATICLIB := libgCtrl.a

TARGET :=  libgCtrl.so
.PHONY : clean all

$(TARGET):$(OBJS)
ifeq ($(BUILD_STATIC_LIB), n)	
	$(CC)  -fPIC -shared  $(CFLAGS)  -o $@ $^ 
else
	@rm -rf $(STATICLIB) 
	$(AR) -r $(STATICLIB) $(OBJS)
endif

%.o:%.c 
	$(CC)   $(CFLAGS)   -c $< -o $@ 	

%.o:%.cpp
	$(C++)   $(CFLAGS)  -c $< -o $@


clean:
	@rm -f $(TARGET)
	@rm -f $(OBJS)
	@rm -rf $(STATICLIB) 


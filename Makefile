
vpath %.c src

RM       :=  rm -f

CC       :=  gcc
CFLAGS   := -std=c17 -Wall -Wextra -Wpedantic -Og -ggdb3 -fanalyzer
CPPFLAGS := -Iinclude -D_GNU_SOURCE
LDFLAGS  := -Wl,-O1,--as-needed,--sort-common,-z,relro,-z,now
LIBS     := -lm -pthread -lSDL2 -ldl -lGLX_nvidia

SRCS     := $(notdir $(wildcard src/*.c))
OBJS     := $(patsubst %.c,%.o,$(SRCS))

TARGET   :=  dominus

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)

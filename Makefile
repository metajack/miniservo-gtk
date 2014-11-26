CC ?= gcc
CFLAGS = -std=c99 -O2 `pkg-config --cflags gtk+-3.0` -Itegtkgl
LDFLAGS = `pkg-config --libs gtk+-3.0` -lGL -lX11 -lm

C_SRC = src/main.c src/app.c src/win.c src/resources.c src/gcef.c tegtkgl/tegtkgl.c
OBJS = $(patsubst %.c,%.o,$(C_SRC))
HEADERS = src/app.h src/win.h src/gcef.h

CEF_CFLAGS = -I/home/jack/src/chromium-embedded-framework/cef3/binary_distrib/cef_binary_3.0.0_linux
CEF_LDFLAGS = -L /home/jack/src/servo/ports/cef/target -lembedding-d068e37ec8e3dc6f

.PHONY: all
all: miniservo

%.o: %.c
	@echo "CC $@"
	@$(CC) $(CFLAGS) $(CEF_CFLAGS) -o $@ -c $< $(CEF_LDFLAGS)

src/resources.c: src/app.gresource.xml src/win.ui
	@echo "GENRES $@"
	@glib-compile-resources $< --target=$@ --sourcedir=src --generate-source

miniservo: $(OBJS) $(HEADERS)
	@echo "CC $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(CEF_LDFLAGS)

.PHONY: clean
clean:
	@rm -f $(OBJS) src/resources.c miniservo

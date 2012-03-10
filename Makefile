EXECUTABLE=xbmcvc
MODELDIR=`pkg-config --variable=modeldir pocketsphinx`
LIBS=`pkg-config --cflags --libs pocketsphinx sphinxbase` -lcurl
GITVERSION=`git log --oneline | cut -d' ' -f1 | head -n1`

all:
	gcc -O3 -o $(EXECUTABLE) $(EXECUTABLE).c -DGITVERSION=\"$(GITVERSION)\" -DMODELDIR=\"$(MODELDIR)\" $(LIBS)

debug:
	gcc -g -o $(EXECUTABLE) $(EXECUTABLE).c -DGITVERSION=\"$(GITVERSION)\" -DMODELDIR=\"$(MODELDIR)\" $(LIBS)

clean:
	rm -rf ./xbmcvc

install:
	install $(EXECUTABLE) /usr/bin; \
	install -m 0644 model/xbmcvc.* $(MODELDIR)/lm/en


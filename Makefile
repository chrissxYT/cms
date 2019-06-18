all:
	@gcc cms.c -Ofast -o cmsd

clean:
	@rm -f cmsd

test:

install:all
	@cp -f cmsd /usr/bin/cmsd
	@cp -f cmsd.service /etc/systemd/system/cmsd.service
	@systemctl enable --now cmsd


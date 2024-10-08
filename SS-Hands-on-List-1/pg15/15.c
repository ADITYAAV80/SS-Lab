/*
NAME: 15.c
AUTHOR: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
15. Write a program to display the environmental variable of the user (use environ).
DATE: 11 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
extern char **environ;

int main(){
	int count =0;
	for(char **env=environ;*env!=NULL;env++){
		printf("%d::%s\n",count,*env);
		count+=1;
	}
}

/* OUTPUT

1)Compile and exceute the program: 15.c

0::SHELL=/bin/bash
1::SESSION_MANAGER=local/laptop:@/tmp/.ICE-unix/1948,unix/laptop:/tmp/.ICE-unix/1948
2::QT_ACCESSIBILITY=1
3::COLORTERM=truecolor
4::XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
5::SSH_AGENT_LAUNCHER=openssh
6::EPIC=hello
7::XDG_MENU_PREFIX=gnome-
8::GNOME_DESKTOP_SESSION_ID=this-is-deprecated
9::GNOME_KEYRING_CONTROL=/run/user/1000/keyring
10::GNOME_SHELL_SESSION_MODE=ubuntu
11::SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
12::XMODIFIERS=@im=ibus
13::DESKTOP_SESSION=ubuntu
14::GTK_MODULES=gail:atk-bridge
15::PWD=/home/aditya/SS-Lab/pg15
16::LOGNAME=aditya
17::XDG_SESSION_DESKTOP=ubuntu
18::XDG_SESSION_TYPE=x11
19::GPG_AGENT_INFO=/run/user/1000/gnupg/S.gpg-agent:0:1
20::SYSTEMD_EXEC_PID=2284
21::XAUTHORITY=/run/user/1000/gdm/Xauthority
22::WINDOWPATH=2
23::HOME=/home/aditya
24::USERNAME=aditya
25::LANG=en_US.UTF-8
26::LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=00:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.avif=01;35:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:*~=00;90:*#=00;90:*.bak=00;90:*.old=00;90:*.orig=00;90:*.part=00;90:*.rej=00;90:*.swp=00;90:*.tmp=00;90:*.dpkg-dist=00;90:*.dpkg-old=00;90:*.ucf-dist=00;90:*.ucf-new=00;90:*.ucf-old=00;90:*.rpmnew=00;90:*.rpmorig=00;90:*.rpmsave=00;90:
27::XDG_CURRENT_DESKTOP=ubuntu:GNOME
28::VTE_VERSION=7200
29::GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/17cc8e83_4abc_4624_bf4d_586f5a8fa7b5
30::LESSCLOSE=/usr/bin/lesspipe %s %s
31::XDG_SESSION_CLASS=user
32::TERM=xterm-256color
33::LESSOPEN=| /usr/bin/lesspipe %s
34::USER=aditya
35::GNOME_TERMINAL_SERVICE=:1.195
36::DISPLAY=:1
37::SHLVL=1
38::QT_IM_MODULE=ibus
39::XDG_RUNTIME_DIR=/run/user/1000
40::DEBUGINFOD_URLS=https://debuginfod.ubuntu.com 
41::XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/usr/local/share/:/usr/share/:/var/lib/snapd/desktop
42::PATH=/home/aditya/anaconda3/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
43::GDMSESSION=ubuntu
44::DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
45::OLDPWD=/home/aditya/SS-Lab/pg14
46::_=./15.out

aditya@laptop:~/SS-Lab/pg15$ echo $USER
aditya

*/

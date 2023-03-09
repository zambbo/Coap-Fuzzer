FROM contiker/contiki-ng:latest

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install vim -y
RUN apt-get install git -y
RUN apt-get install autoconf -y
RUN apt-get install pkg-config -y
RUN apt-get install libtool -y
RUN apt-get install make -y
RUN apt-get install curl -y
RUn apt-get install zsh -y
RUN zsh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)" ||true
RUN apt-get install clang -y
RUN apt-get install g++ -y
RUN apt-get install tmux -y


RUN ln -f /bin/zsh /bin/sh


WORKDIR /home/${user}
RUN git clone https://github.com/obgm/libcoap.git

VOLUME ["/home/zambbo/CoapFuzzer/images"]


CMD ["/bin/sh"]



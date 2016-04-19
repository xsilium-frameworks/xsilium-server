# xsilium-server-lite
FROM debian:sid
MAINTAINER Xelfe <xelfes@gmail.com>

USER root

RUN apt-get update -y

# Installing base dev tools
RUN apt-get install -y --no-install-recommends gcc wget g++ make cmake libpqxx-dev git libbz2-dev

# Installing boost
ENV \
    # The $HOME is not set by default, but some applications needs this variable
    HOME=/opt/app-root/src \
    PATH=/opt/app-root/src/bin:/opt/app-root/bin:$PATH \
    boost_version=1.59.0 \
    boost_dir=boost_1_59_0 \

RUN wget http://downloads.sourceforge.net/project/boost/boost/${boost_version}/${boost_dir}.tar.gz \
    && tar xfz ${boost_dir}.tar.gz \
    && rm ${boost_dir}.tar.gz \
    && cd ${boost_dir} \
    && ./bootstrap.sh --with-libraries=thread,date_time,system,signals,serialization,test \
    && ./b2 --prefix=/usr -j 4 link=shared runtime-link=shared install \
    && ./b2 --clean-all -n \
    && cd .. && rm -rf ${boost_dir} && ldconfig

# User need by the entry point
useradd -u 1001 -r -g 0 -d ${HOME} -s /sbin/nologin \
      -c "Default Application User" default

WORKDIR ${HOME}

ENTRYPOINT ["script/server-entrypoint"]

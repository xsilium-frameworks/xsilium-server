# xsilium-server-lite
FROM jenkinsci/jnlp-slave
MAINTAINER Xelfe <xelfes@gmail.com>

USER root

#update apt

RUN apt-get update -y

# Installing base dev tools
RUN apt-get install -y --no-install-recommends gcc g++ make cmake python-pip libpqxx-dev git python-dev libbz2-dev

# Installing boost
ENV boost_version=1.59.0
ENV boost_dir=boost_1_59_0

RUN wget http://downloads.sourceforge.net/project/boost/boost/${boost_version}/${boost_dir}.tar.gz \
    && tar xfz ${boost_dir}.tar.gz \
    && rm ${boost_dir}.tar.gz \
    && cd ${boost_dir} \
    && ./bootstrap.sh --with-libraries=thread,date_time,system,signals,serialization,test \
    && ./b2 --prefix=/usr -j 4 link=shared runtime-link=shared install \
    && ./b2 --clean-all -n \
    && cd .. && rm -rf ${boost_dir} && ldconfig

# Debug tools
RUN apt-get install -y --no-install-recommends cppcheck \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

RUN pip  install gcovr

USER jenkins

ENTRYPOINT ["jenkins-slave"]

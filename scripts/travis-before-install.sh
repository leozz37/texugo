echo -n | openssl s_client -connect scan.coverity.com:443 | sed -ne '/-BEGIN CERTIFICATE-/,/-END CERTIFICATE-/p' | sudo tee -a /etc/ssl/certs/ca-certificates.crt
pip install --user cpp-coveralls
DEPS_DIR="${TRAVIS_BUILD_DIR}/deps"
mkdir ${DEPS_DIR} && cd ${DEPS_DIR}
travis_retry wget --no-check-certificate https://cmake.org/files/v3.18/cmake-3.18.0-Linux-x86_64.tar.gz
tar -xvf cmake-3.18.0-Linux-x86_64.tar.gz > /dev/null
mv cmake-3.18.0-Linux-x86_64 cmake-install
PATH=${DEPS_DIR}/cmake-install:${DEPS_DIR}/cmake-install/bin:$PATH
cd ${TRAVIS_BUILD_DIR}
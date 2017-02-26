sound_lib_path="./libsndfile-1.0.27/src/sndfile.a"
varstr="g++ tonal.cpp #{sound_lib_path} -lfftw3 -lm -std=c++11 -o tonal.exe"
puts varstr
system(varstr)

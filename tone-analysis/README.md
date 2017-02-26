<h2> Tone and Frequency Analysis </h2>
Note: This is an experimental feature, not yet integrated with the rest of the project.

<h4> Requirements: </h4>
* libsndfile API: Get it [here](http://www.mega-nerd.com/libsndfile/).
* FFTW3: Fast Fourier Transform Library. Get it [here](http://www.fftw.org/).
* Ruby (optional). Get it [here](https://www.ruby-lang.org/en/documentation/installation/).

<h4> To run: </h4>
1. Place audio wave file in the tone-analysis directory. (Grab this from audio recording if needed). Make sure the audio
file is *mono* (single channel), otherwise the program will not run.
2. With ruby, run `ruby rmake.rb`. If you do not have Ruby installed, download the rb file and run the compilation
command from the source code.
3. Run the program with
`./tonal.exe <input wave file> <verbatim = 0 or 1> [optional output wave file] > <redirected output file name>`
Use "1" for verbatim if you want the program to display magnitude for every frequency component for each set of samples. Use "0" if you only want to see the maximum-strength frequency.

<h4> How can this be used with sentiment analysis? </h4>
Often, changes in vocal tone indicate emotion more strongly than words themselves. Analyzing changing frequencies within a person's voice can pick up on anger, or detect sarcasm better.

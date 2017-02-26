# Real Feels #
Real Feels is a program that records your speech and analyzes your emotions. Our goal is that the program will analyze not only words, but tone of voice and context in order to perform sentiment analysis. Based on this analysis, it can then recommend ways to make you feel better. In addition, Real Feels acts like a mental-health tracker that can give people detailed reports of their day-to-day mental state.
This project is a work-in-progress and many features are yet to be implemented. This is an open-source project, and we encourage contributions and redistributions.


<h4> Current Features:</h4>
* Capturing audio and running basic sentiment analysis
* Desktop GUI

<h4> Features in Progress:</h4>
* Recommendation system for music, movies, etc. based on perceived emotions
* Recording history of emotion over a short period
* Frequency and tone analysis with wav files. This is an experiemental feature. All files are currently in the tone-analysis folder and disjoint from the rest of the project.

<h4> Known Issues </h4>
* Desktop GUI and tone analysis programs are not yet integrated with the back-end system.

<h2> How to Use </h2>
<h4> Sentiment Analysis</h4>
* Go to: http://nodeserver7509.cloudapp.net:3700/api
* Give permissions for the browser to use your microphone, and speak the initial command "Hello, I'm home!"
* Start speaking and Real Feels will start to run.

<h4> Audio Tone Analysis </h4>
Note: This program is currently a separate feature, and it is not implemented in Real Feels yet. 
* Capture audio from a microphone, making sure that it's a single-channel (mono) wav file.
* Follow the instructions in [tone-analysis/README.md](tone-analysis/README.md) to perform a Fast Fourier Transform on the wav file.

<h2> Contributor Guide </h2>
If you would like to contribute to [Project Name], please read the file [CONTRIBUTING.md](CONTRIBUTING.md).

<h2> License </h2>
This project is distributed with the GNU General Public License Version 3. Please see the file [LICENSE.txt](LICENSE.txt).

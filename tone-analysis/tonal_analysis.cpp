#include <iostream>
#include "sndfile.h"
#include <random>
#include <time.h>
#include "fftw3.h"
#include "math.h"

#define BUFFER_LENGTH 1024
#define PI 3.1415926536
#define fc 400

#define BANDS 512

using namespace std;


void random_amplitude_modification(double *data,int readcount,int channels,mt19937 &rnGen)
{
    uniform_real_distribution<double> distributor(0,5);

    for(int chan=0;chan<channels;chan++){
        for(int k=chan;k<readcount;k+=channels){
            double g=distributor(rnGen);
            //printf("g is %g  ",g);
            //printf("%g changed to %g\n",data[chan],data[chan]*g);
            data[k]=data[k]*g;
        }
    }
}

void band_analyze(fftw_plan *p)
{
    fftw_execute(*p);
}

int main(int argc, char **argv)
{
    mt19937 rnGen(time(NULL));

    if(argc!=3)
    {
        printf("Usage: ./aud_test <infilename> <outfilename>\n");
        exit(1);
    }
    cout << "Testing sndfile compilation" <<endl;
    static double data[BUFFER_LENGTH];
    static double magnitudes[BANDS];
    SNDFILE *infile, *outfile;
    SF_INFO sfinfo;
    char* infilename=argv[1];
    char* outfilename=argv[2];
    if (! (infile = sf_open(infilename, SFM_READ, &sfinfo)))
	{	/* Open failed so print an error message. */
		printf ("Not able to open input file %s.\n", infilename) ;
        //Print the error message from libsndfile.
		puts (sf_strerror (NULL)) ;
		return 1;
    }

    /*if (! (outfile = sf_open(outfilename, SFM_WRITE, &sfinfo)))
	{	printf("Not able to open output file %s.\n", outfilename) ;
		puts(sf_strerror (NULL)) ;
		return 1 ;
		} ;*/

    int readcount;
    fftw_complex *freqout; fftw_plan p;
    cout << "Number of channels read: " << sfinfo.channels <<endl;
    cout << "Sample rate: " << sfinfo.samplerate << endl;
    cout << "Bin difference: " << (sfinfo.samplerate/BANDS) <<endl;
    if(sfinfo.channels!=1)
        goto skiploop;

    freqout =(fftw_complex*) fftw_malloc(sizeof(fftw_complex) * BANDS);
    p=fftw_plan_dft_r2c_1d(BANDS,data,freqout,FFTW_MEASURE);
    while ((readcount = sf_read_double(infile, data, BUFFER_LENGTH))!=0)
	{
        //cout << "Read " << readcount << " samples." <<endl;

        band_analyze(&p);
        cout << "Frequency analysis: ";
        double max_magn=0;
        for(int j=0; j<BANDS;j++){
            magnitudes[j]=sqrt(freqout[j][0]*freqout[j][0] + freqout[j][1]*freqout[j][1]);
            if(magnitudes[j]>max_magn)
                max_magn=magnitudes[j];
        }
        for(int j=0; j<BANDS;j++){
            magnitudes[j] /= max_magn;
            printf(" %g ",magnitudes[j]);
        }
        printf("\n-------------------------------\n");
        //random_amplitude_modification(data, readcount, sfinfo.channels,rnGen) ;
    };


    skiploop:
    fftw_destroy_plan(p);
    fftw_free(freqout);
    return 0;
}

#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

//Program to compute the english us grade level as diefined by Coleman-Liau.
int main(void)
{
    int length;
    string ext = get_string("Text : ");
    length = strlen(ext);
    float totletter = 0, totword = 1, totsen = 0;
    for (int i = 0; i < length; i++)
    {
        // counts letters
        if (((int)ext[i] > 64 && (int)ext[i] < 91) || ((int)ext[i] > 96 && (int)ext[i] < 123))
        {
            totletter++;
        }
        //counts spaces
        if ((int)ext[i] == 32)
        {
            totword++;
        }
        //counts full stops, exclamation marks and question marks
        if ((int)ext[i] == 46 || (int)ext[i] == 33 || (int)ext[i] == 63)
        {
            totsen++;
        }
    }

    double s, l, grade;
    //l is no of letters per 100 word
    l = (totletter / totword) * 100 ;
    //s is no of sentences per 100 words
    s = (totsen / totword) * 100;
    //englis US grade defined as by Coleman-Liau.
    grade = (0.0588 * l) - (0.296 * s) - 15.8;
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)round(grade));
    }
}

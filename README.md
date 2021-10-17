# logics

This is a little helper program to solve the cybersecurity [ReplyChallenge](https://challenges.reply.com/) that occured on 15th & 16th oct 2021. Statistics on results are here [ReplyChallenge stats](https://challenges.reply.com/tamtamy/challenge/reply-cybersecurity-challenge-2021/stats).

## Problem

The problem to solve is about a logic circuit shown here after: 
![The logic circuit](/images/misc100-readme-1-circuit.png)

The explanation text:
![The story](/images/misc100-readme-1-story.png)

and finally the mem map:
![The Memory Map](/images/misc100-readme-1-memmap.png)

The original [PDF file](misc100-readme-1.pdf)

The final flag to submit was 

'''
{FLG:<found_string>}
'''

## Building

``` 
$ mdir build
$ cd build
$ cmake -G Ninja ..
$ ninja
``` 

## Run

Compute logic circuit outputs and flag. Display flag at end.
```
$ ./logics
in[000] = 000000000  out[000] = 000010000 (016) flag[0] = 'w'
in[001] = 000010000  out[001] = 000011000 (024) flag[1] = 'e'
in[002] = 000011000  out[002] = 000010101 (021) flag[2] = 'e'
in[003] = 000010101  out[003] = 101110101 (373) flag[3] = 'G'
in[004] = 101110101  out[004] = 100110011 (307) flag[4] = 'o'
in[005] = 100110011  out[005] = 100111011 (315) flag[5] = '0'
in[006] = 100111011  out[006] = 100110110 (310) flag[6] = 'd'
in[007] = 100110110  out[007] = 001000110 (070) flag[7] = 'Y'
in[008] = 001000110  out[008] = 000011101 (029) flag[8] = '0'
in[009] = 000011101  out[009] = 101111101 (381) flag[9] = 'u'
flag = {FLG:weeGo0dY0u}
```

## Unit Tests
Tests logs are in:

```
$ cd build
$ ninja test
$ cat Testing/Temporary/LastTest.log
```

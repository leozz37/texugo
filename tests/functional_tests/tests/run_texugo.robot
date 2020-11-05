*** Settings ***
Library         Texugo.py
Test Timeout    1 minute

Documentation
...
...     Testing Texugo image
...

*** Test Cases ***
Running Texugo Docker Image
    Run texugo
    Sleep   5s
    Kill texugo

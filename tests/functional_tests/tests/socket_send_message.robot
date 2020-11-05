*** Settings ***
Library         SocketInjector.py
Test Timeout    1 minute

Documentation
...
...     Testing Texugo Sockets Connection
...

*** Variables ***
${message}      test
${port1}        ${3005}
${port2}        ${3001}
${destination}  ENDPOINT

*** Test Cases ***
Running Texugo Docker Image
    ${result} =         Verify message  ${port1}    ${port2}    ${message}  ${destination}
    Should be equal     ${result}   ${message}

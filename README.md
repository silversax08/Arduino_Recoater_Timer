Project is used to measure the speed between the extremes of a moving object. Specifically, it was used to measure the recoater speed on a LPBF 3D printer. 

Project was build using an arduino UNO, 2 3D printed/machined mounts, & 3 limit switches (https://www.amazon.com/BUYGOO-V-156-1C25-Momentary-Arduino-CYT1046/dp/B07D9C2B6J/ref=sr_1_4?crid=33L1V74NUMPWD&dib=eyJ2IjoiMSJ9.1G3gWzPvOjcOk4IuKM7gaj18fFfj1YQlN2f6LavFpdE7qW7-uYSwAq32OMJwACLgqaFsORcsP1c8uHLZcimNKWtkEpj7r55xc00UPjewJzyOsbbTp-sbtMy6EvKzOup-dns1g7Upqh1EjUVPlzoNUE4AaNt_59TeV6PaCZJW6L_B0t6HAbiU4fICTXsuNhWuGA1CyqsKW98LKnSVuTXn98GxF7UgO6RiVWJDYKdJAP8.UeAwderJiQO6EfTn_Js5a09yB7O9TxaCa6B-meRx2ig&dib_tag=se&keywords=limit+switch&qid=1737409614&sprefix=limit+sw%2Caps%2C248&sr=8-4)

Basic function is as follows: 
- Two limit switches to start/stop timer
- One limit switch to reset timer (limit switches came in a pack of 6 and I didn't want to buy a button as well)
- Communication to the user occurs over the serial monitor
- If "Reset" switch is pressed and no "Start/Stop" switches are pressed, program will delay half a second (accounting for switch rebound) and then run the timer until either "Stop/Start" switch is pressed.
- If "Reset" switch is pressed and a "Start/Stop" switch is pressed, program will delay half a second (accounting for switch rebound) and then start the timer when the "Start/Stop" switch is released. Timer will run until either "Stop/Start" switch is pressed.

# Stepper Motors

- [Stepper Motors](#stepper-motors)
- [Questions](#questions)
- [Initial Research](#initial-research)
- [Options to Buy](#options-to-buy)

# Questions

- What are the different types?
- How to drive them?
- How small can they get?

# Initial Research
For starters this will be focused on finding a stepper motor that would work for the [VOTV Drive project](../../../Projects/VOTV%20Drive/README.md). 
The challenge will be finding a motor that is small enough. The width of the drive is around 26mm, so the length of the motor should be less than 24mm accounting for wall thickness.

For driving the stepper motors there are a [bunch of modules](https://www.pololu.com/category/120/stepper-motor-drivers) that handle all of the logic for stepping or micro stepping. the only control logic required is a step and a direction circuit. I have used these before and for this project I don't need much control. I just want the motor to turn when there is power.

This good [video by IMSAI Guy](https://youtu.be/bZJoiB56N74) shows how a stepper motor can be controlled via hardware. He uses a [GAL22V10](https://web.mit.edu/6.115/www/document/22v10.pdf), a programmable-logic device. This is a bit overkill so I will look at using either discrete transistors or logic gates.

Here is a [Falstad circuit](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAUgoqoQFMBaMMAKDEIBYQG08QUUXBthT9BUEFyq0JAMwCGAGwDOdKCwDu3bAlEChvMVJYA3bijx9shPj0sgR0iRxlOYCFsvP3H5-A7QJCAUVOhYAc28rGyiHPCl1SIZCf19k1OsJSE1uDECUBEJcyC4CouytBgwYstz8wvVKvKpiIqr68pYAJ25dPla6lvKaeByGPqNeixABiqm+fV7qybnx5bBptaKwYlFVzioN2wR16ez2JCqS8BTuGz52KiLiaFJSbA3rYg48BA2WABKuRiR24eDg4DOzkObig0A8TRBmwOkL42R6VRqDUxDyhYHgoyS1SsumB0TR6gAxmT+PYcQ5SVxsIxyIR4YQwFg8IRCAUEC4MEgYHAIKtibTbBhrhY0WNxbV6TLGvNJsJSYtsgBJEDggKHXZ6rLwihsfk3SQiG5UDiWqiiJAI7jMPR0y1K1Zu12iXwe72BXU+saWtLBmK+hwgg3WWWVUO2S0cdjK4SiRPbIpp5VJjg-O5cHMxvOSXPJJmBfZlqhMDaGuaPC2ies-aQ5Ju63PN5Ud9t8Qot7W5vvgA1D6TGx1Ny07VO2liKEAYeIRvjxclGyCXGDOuAcQQcQoYHZgX7qWQge4NhcxG1+8DG4UoFgAFwoUcChAaPvA3A4rzepDwXZiAJe1YH-YhAKIP4CGZBhiGQKgABM6AUABXRQn26V8-VoGsv3xOAsI-IpcC4YiVgQwjInI7BMhosNTwXa5SKvKxmOwO8hVgR8tClJlrho645nlex5XEYSanEciNVMChlkWaTxOhag3HhCI5KKRYTk0lwshycVfAMsN9JiaNWMkJMJLXRcmWMrQLxvc8GkcuZyMc7TL3RJyM0tNzZko1znIGcUOFmEy+ALczQs6HoyB80Q4skfyCMIs9iDw65uX4pkOLAe9uPUvyinIv49nUWLlhYxKNQCrDmGYwJ8XEfDRhfJrKxmSry2-GBCFoyBaN3H4wFogQ0WgD9BEcSAj2IQpSQIkBkLQjCWDSmtHKyy8p3yyAeJ1TgLKKLazLmVdlwO2zCxOmITvLHItsWMTjC0RKqoyl6Zg2y1Epch7DsirbouVX6BiBsKtHBooQrCyI3syN7SRbLQPPc5Z+U+jyMfAfEuGxutccNeq8ZzEHlkc-FnNnLRKfi5AGg8usNyKLGa0ZnJSo0ig8PulHyYTAHqe5nDiysXnhxFyLAxpqNr0O06cg4eW5fzIXHvsR7xP+0pxGqrXIcOlFEpRM7Dr4y7z10uYla4GzJEO865k5nA6Zd5UPPOm2dVzJ2a1Ie0azdpmGn94WZgNYPjtzWnw72HJEvOmPHdbQm3eJmZbid5ZWkOQmc-d5Zzo8-Psjh5ZBQS8uGNNrh0tEcU67J54ay2xua4t1uazmRvzoTn34-LwJG+aZUtpRcUTe1hcly2oOHtzO3Z6Xdu8EtJfjHW0Rzq286dq4vbn2QcQ3cSoPvwYX9wIgoCQIoMD-0gj9j0ERh4MW5b5HQzCenTtO9ttzIMJCIVWhkPZYJtarURDjWciuwKTZE3guf0ZtAi0U4nCA+IDvb9Gzl3WqvFbpmxiG3HIsDA7EK7kRBo50yFlRSoFKOvZC793shrXM5Fk4EL4HbHhy9wrT1trdIW4o3YiL4ZEDyKJJENBbGYSRulyIQOtK4I0joJ4KIaJPLhTFBF8C0TopBTwGgjwQQYkeIjUG5V2o+KB0NSTkTti2HoDj3yaKtrVHoCADRu2doAyih8vH1zosYvxooJr9UGoIPAI0RBnAmroG8Ip0pzUmghJaKFP6rTPBec64pd6NmsXOARxTcnLwwVxbcJQoI7EXAUHQWYDSOSaULZpM4gmdC0F7O2ZlHE5B6UuMyo4+kxCHNOCgmcWAAHtJBPCZDM0gMy4RlUbNgeC2AWBAA) that implements a full step stepper driver for a unipolar motor using logic gates.

[This article ](https://www.globalspec.com/reference/8273/348308/3-8-4-stepper-motors) shows the different drive needed for a unipolar and bipolar motor. This can be driven with a decade or ring counter. [Here](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAUgoqoQFMBaMMAKAHMQHD8Rs1PueXtkJQoLAO6cM-FAlEMMkACwg5oyJOmEh66bPnipi-sQUyqezQCdOCFELP6qT2vE3H7ulKoZeQrlp+Dmo+dhiiKGEe4aJgIX4R4MQoRgLKVPFCiXEhmmCESIoq4NwCeEIFVKLE0KSkYHgYynzEjWDYLABK2pUJeHDgeWIZyGJUMAhBEX3ZhKNZ4raKOmqGK7NiYO5w7L289vsiQhMsAMb7DtkzB6mq2IzkCHXYSnjYH9hNkB0nsD9pDZqCrSEpXQE3PRA8ExYLeXzYQ5RVSaAA2IAweHuqyxQmO41gSBgzDQkC+eEI82R+AgmgAZiAdEIWqkbizeKkwNAibAUCwAC4UFIc6qGPgTcBQaCED5k7DKHx4Dp8PLS+wsuBgNrEeSHbZUAAmdDpAEMAK6o-ksWwIYXiijxEVbeDWxlikqFSLRZAujie4Sif3404MpT3Eo3XD3bDgblSyB8qRh3ge90orSQkGQ6IZ1bIt1e9MANwoSXz-vzEtGRIJUw4CDLYQbkVGpyTq3tkdWMS7QjZBTSvYxWN43a0TJA7P97Ji074pdEM9dc9S09cPt2UjXojZgXbzOUfdWykCtjIi-n58n6-1uwZbVSUZAFPD0djPITe23BYdqVOZ6SJ8r0rDcbHAbZ7n4bYwntTIXUFaDIJcQD+EyThlDqepSDwFJiHcVJnkgLDiBwogEEaHxGGIH0QCNU0LSte9HXZF9J3necuQ-RNn3mScB1Y4MtFxUchAEscpDE0TeNgoTePzbN0ykK8gMdJ8YgfNjUivJcJN45RDx41QTw0LRtKcVjjLSCynF3EyOGUkQAkAw42wXTS3IQfS0mbCgvOYEpPMU8CSntfzVECtJtI4yBDB05BYuiwwfJibYkqSciCKSGIMo81TUK0Hz2Q+C8-wKvKqC+JC0mKtRRhquLWPBRqc101R82AlrDMZUYr3mVzWOTVi+rSZReMxIzeOE7LHRwSIs0c7KkmE0bVCmsqtOFHLZrSVKak2x1SFKqRdufAyTsOyKlrOmLRDW46IIxRywoCMpFpqMpnrMVyfOEnyvvEeykgwQ4rxufreI0m4NPUpINNY6HZNWyaIcddTHWEq87qcndTBm-LWu6qgbmGmIBpHAaFqEgzxq6mnScm+cyfTJjUmE1jhI4uMYE-BCE1UbbQYWyUGAw4iSNw-CKFgYjSMKCjlComi6PNS1XWe7bEMejQN1dUHTCSEnQK-QwNP9FITnEFmMX4Ab+A+d94z5ADboMq9oaN-dadWBGtxNmbvdR5dDGEs3UY9n9fquk5xxBEPg4MntVhp5OR0TvsRxud4joxJPHJuOm9h84ai8MU4SyL0Z-UNqhq3GKUpk94aq9bXM+wjVYSYzCN+H9CxLYxbuiaTu2Y04x3jZ3Q5e9TpYfz75uJVvMDbVZRytqF28BSFVfA0Mba0JFzCsNIvD4AI6Xj5SOWCAVhhqP1WjjRVxjGVj6mcQMzmuJYdEU9W6mZ7cyQCgaAIgiKEF+HhBsuASKMGjlIcEiD5omSkCtYcbVRgF2OmUSyixLIpTKPiKo14UGcHYqsYhgljDzgyFQBg5Do4FBjEwYU7IwBJCnGMGsEoeF11hIiVI+Z6GHDQfwkRvEWF3F4rCPSgwuBVRkVVHwFV8a1RUZYTBqctCVSdDotA8DgS6BBHfOaBiTGTjkU4GEQQ8FyMWMowE9i6qOQcTEPRPAmBlH0Y4rxHjiG0PEAAe3AEIaSFjSAWKlH+NQ4EkCdCAA) is a Falstad simulation.

I wanted to look at using discrete transistors for the logic to drive the stepper. However this was not as simple as it first seemed, so I will stay with logic gates for now.
See [Discrete Transistor Driver](./Discrete_Transistor_Driver.md) for more details. 

The coils will need to be driven with 1 or 2 H-Bridges, depending on the motor type. Here is a [video showing an H-Bridge](https://youtu.be/5b6qWVo6lcU) made with transistors. 

Will need some diodes to handle any back emf, as some motor drivers don't have internal diodes..

https://www.youtube.com/watch?v=hYk9Um9bdCY



# Options to Buy

- [Tiny 8mm Stepper Motor](https://www.aliexpress.com/item/1005009362113907.html), [More info](https://makerselectronics.com/product/micro-miniature-stepper-motor-8mm-2-phase-4-wire-with-copper-gear-for-camera-lenses/)
- [SP-35RC-810S Stepper](https://www.aliexpress.com/item/1005005485719628.html) [More info page 6](https://moatech.com/skin/board/gallery_pdt/catalog_2016.pdf)
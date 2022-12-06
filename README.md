# UE5sim
## Built for testing Unreal engine 5.0 (UE5) usability in creating environments for AI methods

In UE5 a cart pole environment was developed, and a server was deployed to test and evaluate the core idea of distributing the AI agents to different computers.

### Server
The server listens for incoming TCP connections on port 8000.
Protobuf are used for constructing the messages and the server expects to only receive Protobuf messages
The server handles all the communication between the AI client and the environment and checks if the environment has something to send back to the client.

### Environment
The environment consists of both C++ code and Blueprint code.
The C++ code is used for communication with the server, managing the different states of the environment, and exposing variables to the Blueprint code.
The Blueprint code manages the physics of the cartpole and enables the interactive change parameter without the need to recompile.

## Running the code.
* Make sure to download the correct version of UE5 (5.0)
* Clone this GitHub repo. 
* Open the file UE5sim.uproject and click yes to recompile the project.
  * It will sometime give an error; this error can be ignored because it will have built the missing file by itself. If this happens open the file again.
* The UE5 editor should now open
* The environment with the server is started from the UE5 editor by pressing the green arrow.

## Showcase of the cartpole environment
In the following video, the environment is shown where two AI are training in the same environment and are learning the balance the pole.
https://drive.google.com.mcas.ms/file/d/1NeRccoHPtXZQYTX7IFtdz7Efx6FyEzPv/view


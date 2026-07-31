# DatabaseConnectionTest

C++Builder **integration test** for database connectivity (`Project1.bpr`). Instantiates the main form (`Form1`) and pulls in `Form2` from the [**databaseConnection**](../databaseConnection/) project to verify that a shared DB form loads and runs inside a host application.

## Build and run

1. Ensure **databaseConnection** compiles (same C++Builder version).
2. Open `Project1.bpr`, build, and run.
3. Exercise the UI to confirm the embedded connection form behaves as expected.

See the parent [**C++Builder** README](../README.md).

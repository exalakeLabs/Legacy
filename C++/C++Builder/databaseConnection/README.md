# databaseConnection

Reusable **database connection form** for C++Builder (`Project1.bpr`, `Unit2`). Provides `Form2` with VCL data-aware controls wired for a simple DB session. Intended as a dependency of **DatabaseConnectionTest**, not usually run standalone.

## Build

- Open `Project1.bpr` in C++Builder and compile the form unit.
- **DatabaseConnectionTest** links this project’s form into its main application.

Configure the database connection parameters in the form/datamodel for your target BDE or ODBC datasource (era-appropriate).

See the parent [**C++Builder** README](../README.md).

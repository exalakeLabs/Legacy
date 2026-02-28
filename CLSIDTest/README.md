# CLSIDTest

Windows console program that demonstrates **COM component categories**: listing registered categories, registering/unregistering a sample category, and adding/removing components to that category. Uses `comcat.h` and the `ICatInformation` / `ICatRegister` interfaces.

## What it does

- **ListCategories** — List all registered component categories.
- **RegisterCategory** / **UnregisterCategory** — Register or remove a sample category (e.g. “This is the sample category”).
- **AddComponent** / **RemoveComponent** — Add or remove a sample component (CLSID) from that category.
- **ListCategoryMembers** — List components in the sample category.

Build with Visual C++ (uses COM libraries). Run from a command prompt; output is to the console.

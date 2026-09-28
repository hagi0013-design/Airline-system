
This project makes a 24‑seat aircraft that operates Outbound and Inbound flights. The system uses two arrays of `struct Seat`, and supports things like assignment, deletion, alphabetical listing, and empty-seat reporting.

Each seat is represented by an  `id` (1–24), `taken` (0/1), `last` (char[]), and `first` (char[])

The code has two arrays:
- `outbound[24]`
- `inbound[24]`

The program avoids common C issues:
- No scanf for strings
- All names read via `fgets()`**  
- Abort logic** using `'q'` at any prompt  



## AI Test Harness
I used an AI tool to generate `test_input.txt`, requesting:
- Invalid menu choices  
- Long names  
- Names with spaces  
- This is for assigning occupied seats  
- Deleting empty seats  
- operations that have been abandoned 
- Rapid menu switching  

### Bugs I found
- Some of the menu choices were being not read write due to leftover `\n`
- Partial assignments left garbage in seat structs


### Fixes
- Replaced all mixed input with unified input utilities
- Added rollback logic for aborted assignments
- Added strict buffer flushing after every menu read


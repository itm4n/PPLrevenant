# PPLrevenant

[poc.webm](https://github.com/user-attachments/assets/ae9c53f7-6871-47fa-82e7-b975d66b0b39)

This is a proof-of-concept that shows how a technique such as __Bring Your Own Vulnerable DLL__ (BYODLL) could be used to bypass LSA Protection, or more generally execute arbitrary code within Protected Processes on Windows.

For more information, please check out my blog post series entitled "__Ghost in the PPL__".

- [Ghost in the PPL Part 1: BYOVDLL](https://blog.scrt.ch/2024/08/09/ghost-in-the-ppl-part-1-byovdll/)
- [Ghost in the PPL Part 2: From BYOVDLL to Arbitrary Code Execution in LSASS](https://blog.scrt.ch/2024/08/15/ghost-in-the-ppl-part-2-from-byovdll-to-arbitrary-code-execution-in-lsass/)
- [Ghost in the PPL Part 3: LSASS Memory Dump](https://blog.scrt.ch/2024/09/02/ghost-in-the-ppl-part-3-lsass-memory-dump/)

## Credits

- [@GabrielLandau](https://x.com/GabrielLandau/) - [Post about the BYOVDLL technique on Twitter/X](https://x.com/GabrielLandau/status/1580067594568364032)
- [@KeyZ3r0](https://x.com/KeyZ3r0) (a.k.a. k0shl) - [Isolate me from sandbox - Explore elevation of privilege of CNG Key Isolation](https://whereisk0shl.top/post/isolate-me-from-sandbox-explore-elevation-of-privilege-of-cng-key-isolation)
- [@cplearns2h4ck](https://x.com/cplearns2h4ck) (a.k.a. chiefpie) - [PoC for CVE-2023-28229](https://github.com/Y3A/CVE-2023-28229)

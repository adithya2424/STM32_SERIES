# Understanding CPU Programming  

Programming a CPU can be challenging due to the variety of architectures available. To simplify this, it's helpful to think in terms of high-level abstract models. Understanding how different components of a CPU interact provides a clearer and more detailed perspective.  

## CPU Models  
A CPU's behavior can be understood through different models:  
- **Programmer's Model**  
- **Exception Model**  
- **Memory Model**  
- **Debug Model**  

### Focus: Programmer’s Model  
In the programmer’s model, the CPU consists of multiple registers that store data temporarily. The general process is as follows:  
1. Data is loaded from memory into CPU registers.  
2. The Arithmetic Logic Unit (ALU) processes the data.  
3. The result is stored in another register.  
4. The processed data can be written back to memory.  

### Next: Memory Segments  
In the following section, we will explore memory segmentation and how different memory regions are utilized in CPU operations.  

The segments are as below:

Higher Memory
│
├── Stack (Local variables / Function arguments / Return values)
│
├── (Unallocated Memory)
│
├── Heap (Dynamic allocation: malloc / calloc)
│
├── Uninitialized Data (BSS) (Static / Global variables - uninitialized)
│
├── Initialized Data (Static / Global variables - initialized)
│
└── Text (Read-Only, contains code)
---  


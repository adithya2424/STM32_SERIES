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

## Memory Segments  
In the following section, we will explore memory segmentation and how different memory regions are utilized in CPU operations.  

### Memory Layout  

1. **Stack** – Local variables / Function arguments / Return values  
2. **Unallocated Memory**  
3. **Heap** – Dynamic allocation (`malloc` / `calloc`)  
4. **Uninitialized Data (BSS)** – Static / Global variables (uninitialized)  
5. **Initialized Data** – Static / Global variables (initialized)  
6. **Text** – Read-only section (contains code)  

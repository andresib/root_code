
### Prerequisites:
1. A **histos** directory in the same place where the code is run.
2. The root version: ROOT 6.22/00  

### What does the code do?
This code extracts the histograms from the **file.root** which are listed in the file **list.txt**.
The code saves the histograms as png images in the directory **histos**. 

### How to use the code?
Open a root session:
> root -l 

Execute the code inside root:

> .x extract_plots_from_root_file.C("file.root","list.txt")

As an example, try to run with the provided files: Noise_run_337973_2020_10_9__0_27_33.root and list.txt:

> .x extract_plots_from_root_file.C("Noise_run_337973_2020_10_9__0_27_33.root","list.txt")


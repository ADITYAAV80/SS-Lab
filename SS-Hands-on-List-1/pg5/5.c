/*
NAME: 5.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
5)Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
DATE: 9 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	
	int ret[5];
	printf("pid : %d \n",getpid());
	for(;;){
		ret[1] = open("f1.txt", O_CREAT  );
		if(ret[1] != -1){
			printf("f1_open\n");
		}
		else{
			printf("ERROR\n");
			sleep(30);
		}

		ret[2] = open("f2.txt", O_CREAT );
		if(ret[2] != -1){
			printf("f2_open\n");
		}
		else{
			printf("ERROR\n");
			sleep(30);
		}

		ret[3] = open("f3.txt", O_CREAT  );
		if(ret[3] != -1){
			printf("f3_open\n");
		}
		else{
			printf("ERROR\n");
			sleep(30);
		}

		ret[4] = open("f4.txt", O_CREAT );
		if(ret[4] != -1){
			printf("f4_open\n");
		}
		else{
			printf("ERROR\n");
			sleep(30);
		}

		ret[5] = open("f5.txt", O_CREAT );
		if(ret[5] != -1){
			printf("f5_open\n");
		}
		else{
			printf("ERROR\n");
			sleep(30);
			break;
		}

	}
}

/* OUTPUT

1) Compile and execute file : 5.c
2) Open another terminal and go to proc/fd/pid
3) You can see the softlinks 0 1 2 3 4 5 6 7
4) 0, 1, 2 is default rest are your files

IN CURRENT TERMINAL:
aditya@laptop:~/SS-Lab/pg5$ ./5.out
pid : 12435 
f1_open
f2_open
f3_open
f4_open
f5_open
ERROR
ERROR
ERROR
^C

IN OTHER TERMINAL:
aditya@laptop:~/SS-Lab/pg5$ cd ../../../../
aditya@laptop:/$ cd proc
aditya@laptop:/proc$ ls
1      11095  12290  127   16    174   1948  2197  23    250   29    35    45    578   648  7233  851   913  9365  9863           execdomains  misc           tty
10     111    12293  128   1624  175   1978  22    2300  251   3     350   46    579   649  727   852   92   937   99             fb           modules        uptime
100    11165  12294  129   1627  1751  2     2209  2304  252   305   3540  4674  58    65   73    853   920  938   9904           filesystems  mounts         version
101    112    12295  13    163   1753  20    2221  2310  253   306   3583  47    580   650  731   856   921  94    9937           fs           mtrr           version_signature
103    113    12297  130   1630  176   2000  2237  2320  254   31    3593  479   581   665  74    857   922  9404  9944           interrupts   net            vmallocinfo
10379  115    123    131   1639  177   2019  2253  2336  255   32    3659  49    5877  67   75    858   923  95    acpi           iomem        pagetypeinfo   vmstat
10388  1159   12321  1310  1663  178   205   2269  2345  256   33    37    5     59    68   76    859   924  9564  asound         ioports      partitions     zoneinfo
104    11640  12323  133   1664  179   2075  2270  2381  2592  3387  3713  50    6     681  7653  86    925  9629  bootconfig     irq          pressure
10417  11687  12384  135   167   180   209   2272  2384  2593  3392  38    51    600   683  77    8650  926  9631  buddyinfo      kallsyms     schedstat
105    117    124    1353  1670  181   2092  2273  2386  26    3393  3844  516   6025  684  79    866   927  9642  bus            kcore        scsi
10519  11704  12416  136   1673  182   21    2274  2400  2602  3395  385   52    61    689  7970  87    928  9643  cgroups        keys         self
10520  118    12417  137   1674  1827  2101  2278  2420  2623  3397  3866  53    611   69   7988  870   929  9684  cmdline        key-users    slabinfo
106    119    12418  138   168   19    2109  2282  2444  2683  34    3888  5406  612   695  8     874   93   9685  consoles       kmsg         softirqs
107    12     12420  14    1686  1910  2119  2284  245   27    3403  39    5412  6176  696  80    875   930  97    cpuinfo        kpagecgroup  stat
1071   121    12435  141   1687  1917  2127  2285  246   272   3404  4     55    62    70   8073  877   931  9711  crypto         kpagecount   swaps
109    122    12436  15    17    1927  2136  2287  2467  273   3406  40    5518  6224  707  81    88    932  9782  devices        kpageflags   sys
11     12250  12444  151   1706  1928  2149  2291  247   274   3433  4087  56    629   71   82    89    933  9785  diskstats      loadavg      sysrq-trigger
110    12265  12445  154   1710  1930  2179  2294  248   277   3435  41    563   63    714  83    891   934  9790  dma            locks        sysvipc
11060  12277  125    155   1717  1940  2180  2296  249   28    3445  43    57    631   717  8462  895   935  98    driver         mdstat       thread-self
11061  12285  126    157   173   1946  2188  2297  25    280   3469  44    576   64    722  85    91    936  9806  dynamic_debug  meminfo      timer_list
aditya@laptop:/proc$ cd 12435
aditya@laptop:/proc/12435$ ls
arch_status  clear_refs          cpuset   fdinfo             limits     mountinfo   numa_maps      patch_state  schedstat     stack    task            wchan
attr         cmdline             cwd      gid_map            loginuid   mounts      oom_adj        personality  sessionid     stat     timens_offsets
autogroup    comm                environ  io                 map_files  mountstats  oom_score      projid_map   setgroups     statm    timers
auxv         coredump_filter     exe      ksm_merging_pages  maps       net         oom_score_adj  root         smaps         status   timerslack_ns
cgroup       cpu_resctrl_groups  fd       ksm_stat           mem        ns          pagemap        sched        smaps_rollup  syscall  uid_map
aditya@laptop:/proc/12435$ cd fd
aditya@laptop:/proc/12435/fd$ ls
0  1  2  3  4  5  6  7

*/

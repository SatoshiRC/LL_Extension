# 目次

## memo
### Master Transmit
1. check busy
2. enable periferal
3. clear bit POS
4. generate start
5. wait until SB flag is set
6. send slave address
7. wait until ADDR flag is set
8. clear address flag
9. loop until finish to send
   1.  wait until TXE flag is set
       1.  chach is a NACK is detected
           1.  return ERROR
       2.  check for the timeout
           1.  return timeout
   2.  write data to DR
   3.  if BTF flag is set
       1.  write data to DR
   4.  while until BTF flag is set
## ToDo
general callを使うとすべてのデバイスにデータを送れる？？？


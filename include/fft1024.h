if (fft1024.available()) {
    level[0] =  fft1024.read(1);
    level[1] =  fft1024.read(2);
    level[2] =  fft1024.read(3);
    level[3] =  fft1024.read(4);
    level[4] =  fft1024.read(5, 7);
    level[5] =  fft1024.read(7, 9);
    level[6] =  fft1024.read(9, 13);
    level[7] =  fft1024.read(13, 17);
    level[8] =  fft1024.read(17, 23);
    level[9] =  fft1024.read(23, 46);
    level[10] = fft1024.read(46, 69);
    level[11] = fft1024.read(69, 92);
    level[12] = fft1024.read(92, 138);
    level[13] = fft1024.read(138, 207);
    level[14] = fft1024.read(207, 414);
    level[15] = fft1024.read(414, 511);
}
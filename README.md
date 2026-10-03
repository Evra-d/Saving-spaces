#A solution for saving spaces
The document present a way of packing data in a chunk of bit and save it in one variable in order to not lose all those bits who could have made another chunk of data and spaces

For illustration, I take the case where we have to record students grades/marks. And, instead of give a whole *int* or something else able to this space, I decided to split the whole space in the maximum number of bits that one mark can request. Of course one could have just use the *u_int8_t*. This is just the illustration. Then we just play with bits.

Any help or suggestions would be invaluable to me.
Thanks.

***Elegance***

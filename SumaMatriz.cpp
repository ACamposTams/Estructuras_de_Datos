
int sumaM (int a[], int x, int y, int alto, int ancho)
{
    if (x == ancho && y == alto)
        return 0;
    else
        if (x == ancho)
            y++;
            return a[x,y] + sumaM(a,x-1,y,alto,ancho);
        else
            return a[x,y] + sumaM(a,x+1,y,alto,ancho);
}
void oyunu_yukle(void)
{
	allegro_init();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);
	install_mouse();
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT,NULL);
}
/*---------------------------------------*/
void yuklemeler(void)
{
	basla=load_bitmap("basla.bmp",NULL);
	telefon=load_bitmap("telefon.bmp",NULL);
	arakatman=create_bitmap(800,600);
	halkalar=load_bitmap("halkalar.bmp",NULL);
	kutular=load_bitmap("kutular.bmp",NULL);
	yenioyun=load_bitmap("olustur.bmp",NULL);
	bulundu=load_bitmap("bulundu.bmp",NULL);
	bulunamadi=load_bitmap("bulunamadi.bmp",NULL);
	sayiuretme=load_sample("sayiuretme.wav");
	islemyaparken=load_sample("islemyaparken.wav");
	basarili=load_sample("basarili.wav");
	basarisiz=load_sample("basarisiz.wav");
	cikis=load_bitmap("cikis.bmp",NULL);
	sesacik=load_bitmap("sesacik.bmp",NULL);
	seskapali=load_bitmap("seskapali.bmp",NULL);
	muzik=load_sample("muzik.wav");
	uzerinegel=load_sample("uzerinegel.wav");
}
/*---------------------------------------*/
int islem_yap(int s1,int s2,int oper)
{
	int x;
	if(oper==1) x=s1+s2;
	if(oper==2) x=s1-s2;
	if(oper==3) x=s1*s2;
	if(oper==4) x=s1/s2;
	return x;
}
/*---------------------------------------*/
void yerdegistir(int *a, int *b)
{
	int gecici;
	gecici=*a;
	*a=*b;
	*b=gecici;
}
/*---------------------------------------*/
void halkalara_yaz(void)
{
	
	halkalar_x=50; halkalar_y=50;
	for(k=0;k<6;k++)
	{
		textprintf_ex(arakatman,font,halkalar_x+30,halkalar_y+30,makecol(255,0,0),-1,"%d",sayilar[k]);
		halkalar_x+=75;
	}
	halkalar_x+=110; //hedef halkasý
	textprintf_ex(arakatman,font,halkalar_x,halkalar_y+30,makecol(0,0,255),-1,"%d",hedef);
	halkalar_x=50; halkalar_y=50;
}
/*---------------------------------------*/
int operator_uret(int sayi1, int sayi2)
{
	if(sayi1 <= 0 || sayi2 <= 0) op=rand()%2+1;
	else
	{
		if(sayi1 >= sayi2) 
		{
			if(sayi1 % sayi2 == 0) op=rand()%4+1;
			else op=rand()%3+1;
		}
		else
		{
			yerdegistir(&sayi1,&sayi2);
			if(sayi1 % sayi2 == 0) op=rand()%4+1;
			else op=rand()%3+1;
		}
	return op;
	}
}
/*---------------------------------------*/
void ana_ekran(void)
{
	blit(basla,arakatman,0,0,basla_x+1,basla_y,800,600);
	blit(telefon,arakatman,0,0,telefon_x,telefon_y,800,600);
	blit(halkalar,arakatman,0,0,halkalar_x,halkalar_y,800,600);
	blit(kutular,arakatman,0,0,kutular_x,kutular_y,800,600);
	blit(yenioyun,arakatman,0,0,yenioyun_x,yenioyun_y,800,600);
	blit(cikis,arakatman,0,0,cikis_x,cikis_y,800,600);
	
	if(ses_kontrol==1) blit(seskapali,arakatman,0,0,ses_x,ses_y,800,600);
	else blit(sesacik,arakatman,0,0,ses_x,ses_y,800,600);
}
/*---------------------------------------*/
void dongu_ekrani(void)
{
	blit(telefon,arakatman,0,0,telefon_x,telefon_y,800,600);
	blit(halkalar,arakatman,0,0,halkalar_x,halkalar_y,800,600);
	blit(kutular,arakatman,0,0,kutular_x,kutular_y,800,600);
}
/*---------------------------------------*/
void mouse_kontrolleri(void)
{
		if(mouse_x>yenioyun_x && mouse_x<yenioyun_x+yenioyun_uzunluk_x && mouse_y>yenioyun_y && mouse_y<yenioyun_y+yenioyun_uzunluk_y)
		{
			rect(arakatman,yenioyun_x-5,yenioyun_y-5,yenioyun_x+yenioyun_uzunluk_x+5,yenioyun_y+yenioyun_uzunluk_y+5,makecol(0,255,0));
			if(mouse_b & 1)
			{
				play_sample(sayiuretme,800,0,1000,0);
				yeni=1;	
			}
		}

		if(mouse_x>basla_x && mouse_x<basla_x+basla_uzunluk_x && mouse_y>basla_y && mouse_y<basla_y+basla_uzunluk_y)
		{
			
			rect(arakatman,basla_x-5,basla_y-5,basla_x+basla_uzunluk_x+5,basla_y+basla_uzunluk_y+5,makecol(0,0,255));
			
			if(mouse_b & 1)
			{
				play_sample(islemyaparken,800,0,1000,1);
				sonuc=0;
				basla_tik=1; //sonuc hedeften farklý olduðunda iþlem yapacak
				c=0;
				
			}
		}

		if(mouse_x>cikis_x && mouse_x<cikis_x+cikis_uzunluk_x && mouse_y>cikis_y && mouse_y<cikis_y+cikis_uzunluk_y)
		{
			rect(arakatman,cikis_x-5,cikis_y-5,cikis_x+cikis_uzunluk_x+5,cikis_y+cikis_uzunluk_y+5,makecol(255,0,0));
			if(mouse_b & 1)
			{
				play_sample(uzerinegel,255,128,1000,0);
				rest(2000);
				exit(1);
			}
		}

		if(mouse_x>ses_x && mouse_x<ses_x+ses_uzunluk_x && mouse_y>ses_y && mouse_y<ses_y+ses_uzunluk_y)
		{	
			rect(arakatman,ses_x-5,ses_y-5,ses_x+ses_uzunluk_x+5,ses_y+ses_uzunluk_y+5,makecol(255,255,0));	
			if(mouse_b & 1)
			{
				if(ses_kontrol==1)
				{
					stop_sample(muzik);
					ses_kontrol=0;
				}
				else if(ses_kontrol==0)
				{
					play_sample(muzik,500,0,1000,1);
					ses_kontrol=1;
				}
			}
		}
		
}
/*---------------------------------------*/
void ekrani_temizle(void)
{
	blit(arakatman,screen,0,0,0,0,800,600);
	clear_bitmap(arakatman);
}
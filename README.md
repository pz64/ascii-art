# ascii-art-generator

ASCIIArt Generator class generate ascii-art for input image.

Only supported on mono type fonts because the font padding calculation is not yet implemented.

[written in c++, microsoft visualstudio 2019 Comunity Edition.]

used [stb](https://github.com/nothings/stb) lib for reading, writing, resizing image and reading font files.

Example image used is taken from [unsplash.com](https://unsplash.com/photos/70l1tDAI6rM) submitted by Chris Lee.

ascii-art example :


```cpp
#include "image.h"
#include "fontrender.h"
#include "pixelbrightness.h"
#include "asciiart.h"

int main()
{
	/*
	uses default font:
	"./fonts/RobotoMono-Regular.ttf
	currently only support mono fonts.
	*/
	FontRender robotoDefault;

	Image plant("../out/photo_1.jpg");
	plant.resizeWrtWidth(80);

	ASCIIArt art(&plant, &robotoDefault);
	art.outputPath = "../out/art.txt";
	art.generateArt();
}
```
## input
<img src="./out/photo_1.jpg" />

## output
with image width 80

```
_":~;^!~"""__-,,,''-":""__;S/~~=|1a/gQQQQQQQQQQWA',-5S=E]!]a+_`nP,!(F+<||=;!~;^;
_-_"":::"""_-_-,',,''-:~::|C|^r/=:(MWQQQQQQQQQQQ@u-,;#yF=|?j+_``;:=9{?SOh|!;;^;!
"-------------~Tx-,,,',_:;;r<]v;^=oQQQQQQQQQQQQQWp:|-<q):=?j+_``_;>i?kQWQp[^;;;!
^_----------_tGQO"--,,'``-:;<}1~6>|MWQQQQQQQQQQQWS:df>w/_\sJ/_''''T0SHSWWW&SP+=;
3:"_-__----=5&Q&s----,''```'_!_1h?[0WQQQQQQQQQQQQ&/"[oj^"7za1-'```!4Ss1KS0$WW&8A
0L;=_---"1qMQQMs----,'''`'''..'"*l9B@QQQQQQQQQQQQWN+~Y[<y#s{>'````'~;"_"~^/u{L(+
$@R2|![V8&Q&Gd|,,--,'<x''',````--!r)o@QQQQQQQQQQQQW$D7|]a[z}|,```-_,:||~"_-----,
$$$&hrEDd36?^_----,'^NS,','````"",`'!SWQQQQQQQQQQQQ$Xn~,';ai=''``2G3r:;><;:"_---
$$$$Or~:::::"_---,'~S$s`''``.'`"|--'`=0WQQQQQQQQQQWN2r-``^Ti^``,`r$W$#c;;==^!:::
$$$$&J:::::""_-,,'_RQ#-','"n`'`,v!-_,'6WQQQQQQQQQQQR)!,''!}z;,'`,'wQWWQSZ/^!~!;^
$$$$8!~:""__--,,,,Z$0|`',`7A`,`_]?___'1$QQQQQQQQQW0P1_v^'~)c~]d,',-kQWWWW&8P*^=>
$$$0*-!n~"_"_--,,o&&s'''',b[`,`tyc>-"-=&QQQQQQQQQQpt!"X:`~]r~=&4,,--i0WWWWWW&G#d
$$$%~~"KRv;::_,-7&&7''''`|G:`,`aM++!--|&QQQQQQQQQ@Hr-]C,`/+=!,4QE',-'!Jb&WWWWWWW
$$&u":"+8gE|;:~q$$Y''''``C8'`'`n$}<|_->$QQQQQQQQQ8)=-XL'`//=^-"BQ{',-'`-|ZB&QWWW
$$N>:__"j?|!::;Jqi-''''``**'```1QX!!",r$QQQQQQQQ&Ur3c8=`.1P<!~`|0Qx,-_,'''_=)UbM
$$4::"-,;?;"_-,,-''''''```''```^0M=::-+$QQQQQQQQB)]@O#-`.^3r~;,`/@$Y_--,''''''-~
$N|_""_-,=="-,,,,''''''``'''```,)&n"~:kQQQQQQQQ&CrDWWU```_u*/!"`'1MQy~',,''',,,,
$f___":-,-;"----,'''''``'``'```',2H~~|OQQQQQQQQO)c&WWB_``'<ny|:,''^#QG*,'''',,,-
G;____":_,-::=",'''''''`'``'`````,/|=3$QQQQQQQ$drRWWWW5,`'|u0a"-'''-s0$K^,'',,'-
A:"_"__":"-_";:,'''''''''`````````,|E@QQQQQQQQB))&WWWWQD;->I$b:,''''';6GGl~,',>5
I::"""_-___,_":_,''''''''``````````"gQQQQQQQQ&U*pWQWWWWW0Xc2Q$x:-'''',_1R$Ohwp&W
j^""""______,-__-,,,,,,''``'``````',>0QQQQQQQSxg$QQQWWWWW$LqQW$MbqJtaqp0QWWWWWWQ
e=___"_--___-,-___;/<_,`'``''`````',!N$$$$$Q&mU$QQQQQQWWW&n5WWWWWWWWWWWWWWWWWQQQ
d|",-___-----,,"-'I&p-``'`,,```'`'',\@&&&&&&poNWQQQQQQQQW@[gWWWWWWWWWWWWWWWQQQQQ
C>;_,,---,,,,,'-_,o&a`````"~"'''`'',U$&&&&&MVDQQWWQQQQQQW0vBWWWWWWWWWWWWWWWWQQQQ
yrr!_,'',-,,,,,'_";?-`''`;yOI''''''~G$&&&&&#U0QQWWWWWQQQWMvNWWWWWWWWWWWWWWWQQQQQ
B/*s=:_-,''''''''""-,'`''6$@r',''',t&&&&&$M4B$$QWWWWWWQQWOn@WWWWWWWWWWWWWWWQQQQQ
@(<2%(;:"---,'''',_"_''':O$B_'''',"b$&&&&&gD&$$$QWWWWWWWWbx$WQWWWWWWWWWWWWQQQQQQ
$d<>2GSUt/=!"-'''',_:,,'(&&3','',,u&&&&&$NdN$$$$$QWWWWWWWXEQQQQQWWWWWWWWQQQQQQQQ
$Nv||]y@$@MGBgq["'',""_,K$0<,-',,:B$&&&$&Rp&$$0ds{mb&WWQQhUWQQQQQQQQWWQQQQQQQQQQ
$$b*;==vDM&&&&&@Sv,,,:~_D$5---,-,F@M$&&$G50$$Or,,-_~[#&W&upWQQQQQQQQQQQQQQQQQQQQ
$$$S(;^=^1fgG0@&&G~,,,~~1m^-_-,-^NG90$$&RS$$O|,,,,,,,_/%Rs@WWWQQQQQQQQQQQQQQQQQQ
$$$$N}:!^^!;|*xT7*"__,-!!_""____C$5[%&$G%@$M>,,,,-,,,''"\E&0QWWWQQQQQQQQQQQQQQQQ
$$$$$On!~!!!!~~:::~:"___~:""""-v@MF?j%0gO$&t,,,,,,,',,'':*BO0$QWWWQQQQQQQQQQQQQQ
$$&&&@B?==!:~::~~!!~::"__!~::"=G@%lLz+H#&$%_,,,,,'''''''',/8NNM&QQWWWWQQWWWQQQQQ
$$@0@@&O?^=^!~:"""""__"_--~^!"9&gHPFzvlR$&],,,,',~/"'',,'`,>#M@@@&$$M@QWQQQQQQQQ
&&820&@&MP|~!;;;;!::"_-,,'':|\ROAKql7V\n&M^,''"cDMN!',''''-';CSbRDgpgb0QWWWQQQQQ
@&R:(G&@&&Gdu\/*+ctomUH+,'''"cKpR%5eeT~<@G:':FO&Q@n,,,',,,-,,:J5yAqCHm5p0QQQQQQW
@&b;"r%@&&&&&0000@&&&$$b-',,,_[%bKFa9[|K$G~rS$$$@z--',",,----,_ny8NNGbRd%G$QWWQW
@&N/!:;{8@&&&&&&&&&&&&8<',--,,_/A4(P7Zp&$M{N$$$0t_-''[3,,--,,--_|4SGOGNNNNGSG&QW
@@@o=!~;>7gG@&&&&&&0ST~-___-,,',|YkdS@%0$&0$$&Ov_,''!O?'-,,<!__:-:}DXHoI{7HA%b@W
@@&p\=!~~^>ca9CKdkI*;""""_,','''->vE$GsB$$$M%}^-,''_RS",,,:Oq__~:__<jw}j7suxTk%N
@@@0l1|!~~~!^^;!!~~:"""-,''''`''--_!Dy2R&$0*_-,,,,,Z&v,-,,1&b:_~~:"_!(d0&@MGSRdA
@@@&Ou\>^!;;!!!~~~::_-,''';3(',-,','~YXRO$O:-,,-,,(&p_-,,,a$B~-:!:!:::1X@QWWWWQ@
@@&&&8(+r^~~~:":_-,,,''';3M@*',,',-,'"rhg0N!___--rM$?,-,--q$G;-"!;bK^!~!]DN@$QWW
@&&&&&5//<^!"__-,,,,,,;3N$&i,,-,,,-,,,"~{B@r-"__^S$G~_-,-_R$N^__!^NQx;~=;!?dgbSN
@&&&&&Mt<|^~:"_---,,^PN$&&m----,,,--,,-"!g&T_"_:X$$H-_---:S$0<__!;bW8=!;1^_!sAAC
@&&&&&&p<^;~"_--,_/5M&&&&X:__-,,_-_-,,,_:V$B;""}&$@r--,__~O$@r"_~;VW$?;~r\=--=lB
@&&&&&&@h;!~:__!?#@$&&&&%!""_-,:D\__,,,-")&&A:^O$$B:-,--_;G$@*"":;[@W%;:;[[!~!"*
&&&&&&&&0qnc])4O&$&&&&@C^~!~_-,Z$7"",-,-_n&$&qU&&&j--,--_^G$&)""_^|gW0r~"r()O0a"
&&&&&&&&&&@00&&&&&&&&Gj;!;;:_,~G$2~~,----2$&&&&&$M<_-,-_"^O$$H::_!=(@Qe~:~+LOW$?
&&&&&&&&&&&&&&&&&&bpD(=^|^~:_,v&$7;;--_-~B$&&&&&$G^_-,-_";8$$R~~":|>%QO^:_=]m&WN
&&&&&&&&&&&&&&&&&&y*]1<|^~:"""D$&)~~--_-iQQ$&&&&&@v-_---_~R$$O^~:_;>(MQF:_"<cRQW
&&&&&&&&&&&&&&&&&&Oc/1>|^;~"~|M$@]::--_;GWWQ&&&&&$S;---__~C$&@n:~""|rq&N<:_">nbQ
&&&&&&&&&&&&&&&&&&@d*/<=^;:~!}&$N|::--"m$QWWQ&&&&&&#=--__:*M$$4~~"":=/D$X;:":|]D
&&&&&&&&&&&&&&&&&@@0m/r|;~~;!C$$b~"_-_v@$$QWWQ&&&&&$Ga!_"":4$&G>~:""~;*S&j;~":=1
&&&&&&&&&&&&&&&@@@&&0d*<^=^;;R$$9::_-<O$$$QWWW$&&&&&$&S2*^~1G&&C;~""":!(GMc;!::!
&&&&&&&&&&&&&&@@@&&&&@bi/r^;rG$M/~~:]O$$$$$QWWQ$&&&&&&$&@G##N&&0o=:""":!v#b[^!:"
&&&&&&&&&&&&&@@@&&&&&&&0S%qqb&0k]n7R0$$$$$$$QWWQ$&&&&&&&&&$$&&&&@8w=:::::;[I*=;~
```

## output
with image width 300
<img src="./out/screenshot_2.jpg" />

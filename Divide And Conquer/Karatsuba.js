// Aman Modan
// 7 August 
function Karatsuba(x, y)
{

if(x<10||y<10)
return x*y;

else{

  

let  n= Math.max(x.toString().length, y.toString().length)
let half =Math.floor(n/2);
const pow=10**half;  //10^n/2
const [a,b,c,d]=[Math.floor(x/pow),x%pow,Math.floor(y/pow),y%pow]

    let ac =Karatsuba(a,c);
    let bd= Karatsuba(b,d);
    let ad_plus_bc=Karatsuba(a+b, c+d)-ac-bd ;
console.log(ac,bd,ad_plus_bc)
    return (ac*10**(2*half) +ad_plus_bc*10**half+bd);   // complexity   O(n)
}
}

console.log(Karatsuba(123456, 2893345));

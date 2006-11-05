using System;

namespace IrrlichtNETCP
{
	public static class NewMath
	{
	 	public static int Sqr(int a) { return a * a; }
	 	public static long Sqr(long a) { return a * a; }
	 	public static float Sqr(float a) { return a * a; }
        public static double Sqr(double a) { return a * a; }
        public static decimal Sqr(decimal a) { return a * a; }
        
        public static float FCos(float angle) { return (float)Math.Cos(angle); }
        public static float FSin(float angle) { return (float)Math.Sin(angle); }
        public static float FTan(float angle) { return (float)Math.Tan(angle); }
        public static float FCos(double angle) { return (float)Math.Cos(angle); }
        public static float FSin(double angle) { return (float)Math.Sin(angle); }
        public static float FTan(double angle) { return (float)Math.Tan(angle); }

        public const float PI = 3.14159265f;
        public const float RADTODEG = 180f / PI;
        public const float DEGTORAD = PI / 180f;
		public const float ROUNDING_ERROR	= float.Epsilon;
		
		public static bool Equals(float a, float b)
		{
			return (a + ROUNDING_ERROR > b) && (a - ROUNDING_ERROR < b);
		}
	}	
}

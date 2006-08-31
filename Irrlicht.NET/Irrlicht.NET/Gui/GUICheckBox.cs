using System;
using System.Runtime.InteropServices;

namespace IrrlichtNETCP
{	
	public class GUICheckBox : GUIElement
	{		
		public GUICheckBox(IntPtr raw) : base(raw)
		{
        }

        public bool Checked
        {
            get
            {
                return GUICheckBox_IsChecked(_raw);
            }
            set
            {
                GUICheckBox_SetChecked(_raw, value);
            }
        }

        #region Native Invokes
        [DllImport(Native.Dll)]
	    static extern bool GUICheckBox_IsChecked(IntPtr checkbox);

        [DllImport(Native.Dll)]
        static extern void GUICheckBox_SetChecked(IntPtr checkbox, bool ck);
        #endregion
    }
	
}

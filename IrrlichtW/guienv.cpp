#include "guienv.h"

IGUIEnvironment *GetGui(IntPtr guienv)
{
	return ((IGUIEnvironment*)guienv);
}

IntPtr GuiEnv_AddButton(IntPtr guienv, M_RECT rectangle, IntPtr parent, int id, M_STRING text)
{
	return GetGui(guienv)->addButton(MU_RECT(rectangle), (IGUIElement*)parent, id, MU_WCHAR(text));
}

IntPtr GuiEnv_AddCheckBox(IntPtr guienv, bool checked, M_RECT rectangle, IntPtr parent, int id, M_STRING text)
{
	return GetGui(guienv)->addCheckBox(checked, MU_RECT(rectangle), (IGUIElement*)parent, id, MU_WCHAR(text));
}

IntPtr GuiEnv_AddComboBox(IntPtr guienv, M_RECT rectangle, IntPtr parent, int id)
{
	return GetGui(guienv)->addComboBox(MU_RECT(rectangle), (IGUIElement*)parent, id);
}

IntPtr GuiEnv_AddContextMenu(IntPtr guienv, M_RECT rectangle, IntPtr parent, int id)
{
	return GetGui(guienv)->addContextMenu(MU_RECT(rectangle), (IGUIElement*)parent, id);
}

IntPtr GuiEnv_AddEditBox(IntPtr guienv, M_STRING text, M_RECT rectangle, bool border, IntPtr parent, int id)
{
	return GetGui(guienv)->addEditBox(MU_WCHAR(text), MU_RECT(rectangle), border, (IGUIElement*)parent, id);
}

IntPtr GuiEnv_AddFileOpenDialog(IntPtr guienv, M_STRING title, bool model, IntPtr parent, int id)
{
	return GetGui(guienv)->addFileOpenDialog(MU_WCHAR(title), model, (IGUIElement*)parent, id);
}
IntPtr GuiEnv_AddImage(IntPtr guienv, M_RECT rectangle, IntPtr parent, int id, M_STRING text)
{
	return GetGui(guienv)->addImage(MU_RECT(rectangle), (IGUIElement*)parent, id, MU_WCHAR(text));
}

IntPtr GuiEnv_AddImageA(IntPtr guienv, IntPtr image, M_POS2DS pos, bool useAlphaChannel, IntPtr parent, int id, M_STRING text)
{
	return GetGui(guienv)->addImage((ITexture*)image, MU_POS2DS(pos), useAlphaChannel, (IGUIElement*)parent, id, MU_WCHAR(text));
}

IntPtr GuiEnv_AddInOutFader(IntPtr guienv, M_RECT rectangle, IntPtr parent, int id)
{
	if(rectangle != NULL)
		return GetGui(guienv)->addInOutFader(&MU_RECT(rectangle), (IGUIElement*)parent, id);
	else
		return GetGui(guienv)->addInOutFader(NULL, (IGUIElement*)parent, id);
}

IntPtr GuiEnv_AddListBox(IntPtr guienv, M_RECT rectangle, IntPtr parent, int id, bool drawBackground)
{
	return GetGui(guienv)->addListBox(MU_RECT(rectangle), (IGUIElement*)parent, id, drawBackground);
}

IntPtr GuiEnv_AddMenu(IntPtr guienv, IntPtr parent, int id)
{
	return GetGui(guienv)->addMenu((IGUIElement*)parent, id);
}

IntPtr GuiEnv_AddMeshViewer(IntPtr guienv, M_RECT rectangle, IntPtr parent, int id, M_STRING text)
{
	return GetGui(guienv)->addMeshViewer(MU_RECT(rectangle), (IGUIElement*)parent, id, MU_WCHAR(text));
}

IntPtr GuiEnv_AddMessageBox(IntPtr guienv, M_STRING caption, M_STRING text, bool modal, EMESSAGE_BOX_FLAG flags, IntPtr parent, int id)
{
	return GetGui(guienv)->addMessageBox(MU_WCHAR(caption), MU_WCHAR(text), modal, flags, (IGUIElement*)parent, id);
}

IntPtr GuiEnv_AddScrollBar(IntPtr guienv, bool horizontal, M_RECT rectangle, IntPtr parent, int id)
{
	return GetGui(guienv)->addScrollBar(horizontal, MU_RECT(rectangle), (IGUIElement*)parent, id);
}

IntPtr GuiEnv_AddStaticText(IntPtr guienv, M_STRING text, M_RECT rectangle, bool border, bool wordWrap, IntPtr parent, int id, bool fillBack)
{
	return GetGui(guienv)->addStaticText(MU_WCHAR(text), MU_RECT(rectangle), border, wordWrap, (IGUIElement*)parent, id, fillBack);
}

IntPtr GuiEnv_AddTab(IntPtr guienv, M_RECT rectangle, IntPtr parent, int id)
{
	return GetGui(guienv)->addTab(MU_RECT(rectangle), (IGUIElement*)parent, id);
}

IntPtr GuiEnv_AddTabControl(IntPtr guienv, M_RECT rectangle, IntPtr parent, bool fillbackGround, bool border, int id)
{
	return GetGui(guienv)->addTabControl(MU_RECT(rectangle), (IGUIElement*)parent, fillbackGround, border, id);
}

IntPtr GuiEnv_AddToolBar(IntPtr guienv, IntPtr parent, int id)
{
	return GetGui(guienv)->addToolBar((IGUIElement*)parent, id);
}

IntPtr GuiEnv_AddWindow(IntPtr guienv, M_RECT rectangle, bool modal, M_STRING text, IntPtr parent, int id)
{
	return GetGui(guienv)->addWindow(MU_RECT(rectangle), modal, MU_WCHAR(text), (IGUIElement*)parent, id);
}

IntPtr GuiEnv_CreateSkin(IntPtr guienv, EGUI_SKIN_TYPE type)
{
	return GetGui(guienv)->createSkin(type);
}

void GuiEnv_DrawAll(IntPtr guienv)
{
	GetGui(guienv)->drawAll();
}

IntPtr GuiEnv_GetFont(IntPtr guienv, M_STRING filename)
{
	return GetGui(guienv)->getFont(filename);
}

IntPtr GuiEnv_GetRootGUIElement(IntPtr guienv)
{
	return GetGui(guienv)->getRootGUIElement();
}

IntPtr GuiEnv_GetSkin(IntPtr guienv)
{
	return GetGui(guienv)->getSkin();
}

IntPtr GuiEnv_GetVideoDriver(IntPtr guienv)
{
	return GetGui(guienv)->getVideoDriver();
}

bool GuiEnv_HasFocus(IntPtr guienv, IntPtr element)
{
	_FIX_BOOL_MARSHAL_BUG(GetGui(guienv)->hasFocus((IGUIElement*)element));
}

bool GuiEnv_PostEventFromUser(IntPtr guienv, IntPtr event)
{
	_FIX_BOOL_MARSHAL_BUG(GetGui(guienv)->postEventFromUser(*((SEvent*)event)));
}

void GuiEnv_RemoveFocus(IntPtr guienv, IntPtr element)
{
	GetGui(guienv)->removeFocus((IGUIElement*)element);
}

void GuiEnv_SetFocus(IntPtr guienv, IntPtr element)
{
	GetGui(guienv)->setFocus((IGUIElement*)element);
}

void GuiEnv_SetSkin(IntPtr guienv, IntPtr skin)
{
	GetGui(guienv)->setSkin((IGUISkin*) skin);
}
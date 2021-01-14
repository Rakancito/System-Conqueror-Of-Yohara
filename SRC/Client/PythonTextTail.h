//Search

		void AttachLevel(DWORD dwVID, const char* c_szText, const D3DXCOLOR& c_rColor);
		void DetachLevel(DWORD dwVID);
    
 //Add after
 
 #ifdef ENABLE_CONQUEROR_LEVEL
		void AttachConquerorLevel(DWORD dwVID, const char* c_szText);
#endif

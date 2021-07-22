//bool List::searchAGoods()
//{
//	int ch;
//	bool isExist = false;
//	while (1)
//	{
//		cout << "\n***************************** MENU ***************************";
//		cout << "\n*          Chon cong viec can thuc hien :                      *";
//		cout << "\n*          1. Tim kiem theo ten vat tu .                       *";
//		cout << "\n*          2. Tim kiem theo ma vat tu .                        *";
//		cout << "\n*          3. Tim kiem theo loai vat tu .                      *";
//		cout << "\n****************************************************************";
//		cout << "\nchon : ";
//		cin >> ch;
//		string ast;
//		if (ch < 1 || ch > 3)
//			cout << "\nchon chua hop le, chon lai.";
//		switch (ch)
//		{
//		case 1:
//		{
//			string input_name;
//			cout << "-Nhap ten vat tu can tim: ";
//			cin.ignore();
//			//cin >> tn;
//			getline(cin, input_name);
//			input_name = To_upper(input_name);
//			string goods_name;
//			for (int i = 0; i < this->size; i++)
//			{
//				goods_name = To_upper(a[i].ten);
//				if (input_name.compare(goods_name) == 0)
//				{
//					printLine(35);
//					a[i].output();
//					isExist = true;
//				}
//			}
//			break;
//		}
//		case 2:
//		{
//			string code_input;
//			cout << "-Nhap ma vat tu can tim: ";
//			cin >> code_input;
//			code_input = To_upper(code_input);
//			string goods_code;
//			for (int i = 0; i < this->size; i++)
//			{
//				goods_code = To_upper(a[i].mvt);
//				if (code_input.compare(goods_code) == 0)
//				{
//					printLine(35);
//					a[i].output();
//					isExist = true;
//				}
//			}
//			break;
//		}
//		case 3:
//		{
//			string l;
//			cout << "-Nhap loai vat tu can tim: ";
//			cin.ignore();
//			getline(cin, l);
//			string L = To_upper(l);
//			string LOAI;
//			int d = 0;
//			for (int i = 0; i < this->size; i++)
//			{
//				LOAI = To_upper(a[i].loai);
//				d = i;
//				if (L.compare(LOAI) == 0)
//				{
//					printLine(35);
//					a[i].output();
//					isExist = true;
//				}
//			}
//			break;
//		}
//		}
//		return isExist;
//	}
//}
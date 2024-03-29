#ifndef GameBoardCellH
#define GameBoardCellH

#include <SFML/Graphics.hpp>

/******************************************************************************************************
*	��������� ��������� ����� ������
******************************************************************************************************/
enum CellState {
    Empty       //  �� ���� ����� �� ������� ����:     ������ 
    , Deck      //  �� ���� ����� �� ������� ����:     ���������� �������
    , Miss      //  ��� ���� �� ������� ����:          ������� � ������ ������� ��� ("��������")
    , HitDeck   //  ��� ���� �� ������� ����:          ������� � ������ ������� ���� ("�����")
};
/******************************************************************************************************
* ����� ������
******************************************************************************************************/
class GameBoardCell {
private:
    int         ind_x;      // ���������� ������ � ������� ��������� "������� �����"
    int         ind_y;      // ���������� ������ � ������� ��������� "������� �����"
    int         x;          // ���������� ������ � ������� ��������� "�����"
    int         y;			// ��������� ������  � ������� ��������� "�����"
    int         width;		//������
    int         height;		//������
    CellState	state;		//��������� ��������� ������

    bool		isVisible = true; //����� �� ��������� ������

public:
    bool		isSelectCell;						//������� �� ������

	GameBoardCell(int ind_x = 0, int ind_y = 0, int x = 0, int y = 0, int w = 30, int h = 30, CellState state = Miss);
    
	int  get_ind_x();
	int  get_ind_y();
	CellState GetState();
	int GetX();
	int GetY();

	void set_ind_x(int ind_x);
	void set_ind_y(int ind_y);
	void SetHeight(int height);
	void SetWidth(int width);
	void SetIsVisible(int isVisible);
	void SetX(int x);
	void SetY(int y);
	void setIsSelectCell(bool isSelectCell);
	void SetState(CellState state);
	
	bool TryHit(int x, int y);
	bool MouseMove(sf::Vector2i mouse_pos);
	void draw(sf::RenderTarget &target, sf::RenderStates states)const;
};
#endif
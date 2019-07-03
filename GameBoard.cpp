#include "TModels.h"

void TModels::select(sf::Vector2i mouse_pos) {
	for (int i = 0; i<v_model.size(); ++i) {
		if (v_model[i].select(mouse_pos)) {
			last_index_select = i;
			break;
		}
	}
	select_by_index(last_index_select);
}

void TModels::select_by_index(int ind) {
	last_index_select = ind;
	if (last_index_select >= 0 && last_index_select < v_model.size()) {
		v_model[last_index_select].isSelect = true;
		model = v_model[last_index_select];
		model.coord0 = std::pair<int, int>(0, 0);
	}
}

void TModels::next_select() {
	bool isNotSelected = true;
	for (int i = 0; i < v_model.size(); ++i) {
		if (v_model[i].isSelect) {
			isNotSelected = false;
			break;
		}
	}

	if (isNotSelected) {
		for (int i = 0; i < v_model.size(); ++i) {
			if (v_model[i].isSelectable) {
				select_by_index(i);
				break;
			}
		}
	}
}

TModels::TModels() {
	//*
	//  ПРИМИТИВ 4-х ПАЛУБНОГО
	{
		TModel model;
		model.coord0 = std::pair<int, int>(0, 0);
		model.buf.push_back(std::pair<int, int>(0, 0));
		model.buf.push_back(std::pair<int, int>(1, 0));
		model.buf.push_back(std::pair<int, int>(2, 0));
		model.buf.push_back(std::pair<int, int>(3, 0));
		model.set(x0, y0, width, height);
		v_model.push_back(model);
	}
	{
		TModel model;
		model.coord0 = std::pair<int, int>(2, 2);
		model.buf.push_back(std::pair<int, int>(0, 0));
		model.buf.push_back(std::pair<int, int>(0, 1));
		model.buf.push_back(std::pair<int, int>(0, 2));
		model.buf.push_back(std::pair<int, int>(0, 3));
		model.set(x0, y0, width, height);
		v_model.push_back(model);
	}


	//  ПРИМИТИВ 3-х ПАЛУБНОГО
	//----------------------------------------------------------------------
	{
		TModel model;
		model.coord0 = std::pair<int, int>(5, 0);
		model.buf.push_back(std::pair<int, int>(0, 0));
		model.buf.push_back(std::pair<int, int>(1, 0));
		model.buf.push_back(std::pair<int, int>(2, 0));
		model.set(x0, y0, width, height);
		v_model.push_back(model);
	}
	{
		TModel model;
		model.coord0 = std::pair<int, int>(6, 2);
		model.buf.push_back(std::pair<int, int>(0, 0));
		model.buf.push_back(std::pair<int, int>(0, 1));
		model.buf.push_back(std::pair<int, int>(0, 2));
		model.set(x0, y0, width, height);
		v_model.push_back(model);
	}
	//*/

	//  ПРИМИТИВ 2-х ПАЛУБНОГО
	//----------------------------------------------------------------------
	{
		TModel model;
		model.coord0 = std::pair<int, int>(9, 0);
		model.buf.push_back(std::pair<int, int>(0, 0));
		model.buf.push_back(std::pair<int, int>(1, 0));
		model.set(x0, y0, width, height);
		v_model.push_back(model);

	}
	{
		TModel model;
		model.coord0 = std::pair<int, int>(9, 2);
		model.buf.push_back(std::pair<int, int>(0, 0));
		model.buf.push_back(std::pair<int, int>(0, 1));
		model.set(x0, y0, width, height);
		v_model.push_back(model);

	}

	//  ПРИМИТИВ 1-х ПАЛУБНОГО
	//----------------------------------------------------------------------
	{
		TModel model;
		model.coord0 = std::pair<int, int>(12, 0);
		model.buf.push_back(std::pair<int, int>(0, 0));
		model.set(x0, y0, width, height);
		v_model.push_back(model);
	}

	next_select();
}

//функция, контролирующая количество возможных типов кораблей на поле (4х-палубный один, 3х-палыбных два и тд)
void TModels::lock(int count) {
	for (int i = 0; i < v_model.size(); ++i) {
		if (v_model[i].buf.size() == count) {
			v_model[i].isSelectable = false;
			v_model[i].isSelect = false;
		}
	}
}

//функция, дающаяя возможность выбрать данный тип корабля для размещения его на поле
void TModels::unlock() {
	for (int i = 0; i < v_model.size(); ++i) {
		v_model[i].isSelectable = true;
	}
}

//функция для проверки: все ли корабли расставлены или нет (одно из условий начала игры)
bool TModels::AllLock() {
	bool isResult = true;
	for (int i = 0; i < v_model.size(); ++i) {
		if (v_model[i].isSelectable == true) {
			isResult = false;
			break;
		}
	}
	return isResult;
}

//функция прорисовки кораблей
void TModels::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < v_model.size(); ++i) {
		v_model[i].draw(target, states);
	}
}

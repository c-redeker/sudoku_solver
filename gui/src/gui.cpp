#include <gui.hpp>

#include <QHeaderView>

SudokuGui::SudokuGui(int &argc, char *argv[]) : m_q_application{argc, argv} {
    m_table_widget.setRowCount(9);
    m_table_widget.setColumnCount(9);
    m_table_widget.setShowGrid(true);
    m_table_widget.setSortingEnabled(false);
    m_table_widget.setLineWidth(9);

    m_table_widget.horizontalHeader()->setDefaultSectionSize(60);
    m_table_widget.horizontalHeader()->setHighlightSections(false);
    m_table_widget.horizontalHeader()->setVisible(false);

    m_table_widget.verticalHeader()->setDefaultSectionSize(60);
    m_table_widget.verticalHeader()->setHighlightSections(false);
    m_table_widget.verticalHeader()->setVisible(false);

    for (int row_index{0}; row_index < 9; ++row_index) {
        for (int column_index{0}; column_index < 9; ++column_index) {
            auto *item = new QTableWidgetItem();
            item->setTextAlignment(Qt::AlignCenter);
            m_table_widget.setItem(row_index, column_index, item);
        }
    }
}

void SudokuGui::DisplaySudoku(const Sudoku &sudoku) {
    for (const auto cell : sudoku.GetAllCells()) {
        auto table_item = m_table_widget.item( cell->GetRowIndex(), cell->GetColumnIndex());

        if (cell->IsCellFilled()) {
            CreateFilledCellItem(table_item, cell->GetNumber());
        } else {
            CreateEmptyCellItem(table_item, cell->GetPossibleNumbers());
        }
    }
    m_table_widget.show();
    m_q_application.exec();
}

void SudokuGui::CreateFilledCellItem(QTableWidgetItem *item, const std::size_t number) {
    QColor green{0, 128, 0};
    item->setTextColor(green);
    QFont font{"Times", 20, QFont::Bold};
    item->setFont(font);
    QString string = QString::number(number);
    item->setText(string);
}

void SudokuGui::CreateEmptyCellItem(QTableWidgetItem *item, const std::vector<std::size_t> &possible_numbers) {
    QColor gray{128, 128, 128};
    item->setTextColor(gray);

    QString string{};
    for (int number{1}; number < 10; ++number) {
        if (std::find(possible_numbers.begin(), possible_numbers.end(), number) != possible_numbers.end()) {
            string.append(QString::number(number));
        } else {
            string.append(" ");
        }
        string.append(" ");
        if (number == 3 || number == 6) { string.append("\n"); }
    }

    item->setText(string);
}
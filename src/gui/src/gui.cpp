#include <gui.hpp>

#include <QHeaderView>

static constexpr int kCountRowsColumns{9};
static constexpr int kCellSize{65};

SudokuGui::SudokuGui(std::shared_ptr<Sudoku> sudoku, std::shared_ptr<SudokuSolver> solver)
    : m_sudoku(sudoku), m_solver(solver) {
    
    this->setFixedSize(kCountRowsColumns * kCellSize + 150, kCountRowsColumns * kCellSize + 50);

    CreateTableWidget();
    CreateButtonSolve();
    DisplaySudoku();
    show();
}

void SudokuGui::CreateTableWidget() {
    m_table_widget.setRowCount(kCountRowsColumns);
    m_table_widget.setColumnCount(kCountRowsColumns);
    m_table_widget.setShowGrid(true);
    m_table_widget.setSortingEnabled(false);
    m_table_widget.setLineWidth(2);

    m_table_widget.horizontalHeader()->setDefaultSectionSize(kCellSize);
    m_table_widget.horizontalHeader()->setHighlightSections(false);
    m_table_widget.horizontalHeader()->setVisible(false);

    m_table_widget.verticalHeader()->setDefaultSectionSize(kCellSize);
    m_table_widget.verticalHeader()->setHighlightSections(false);
    m_table_widget.verticalHeader()->setVisible(false);

    m_table_widget.move(10, 10);
    m_table_widget.resize(kCountRowsColumns * kCellSize + 10, kCountRowsColumns * kCellSize + 10);

    for (int row_index{0}; row_index < 9; ++row_index) {
        for (int column_index{0}; column_index < 9; ++column_index) {
            auto *item = new QTableWidgetItem();
            item->setTextAlignment(Qt::AlignCenter);
            m_table_widget.setItem(row_index, column_index, item);
        }
    }
}

void SudokuGui::CreateButtonSolve() {
    m_button_solve.move(kCountRowsColumns * kCellSize + 30, 10);
    m_button_solve.resize(100, 40);
    m_button_solve.setText("Solve");
    bool success = connect(&m_button_solve, &QPushButton::clicked, this, &SudokuGui::SolveAndDisplaySudoku);
    Q_ASSERT(success);
}

void SudokuGui::SolveAndDisplaySudoku() {
    SolveSudoku();
    DisplaySudoku();
}

void SudokuGui::SolveSudoku() { m_solver->Solve(*m_sudoku); }

void SudokuGui::DisplaySudoku() {
    for (const auto cell : m_sudoku->GetAllCells()) {
        auto table_item = m_table_widget.item(cell->GetRowIndex(), cell->GetColumnIndex());

        if (cell->IsCellFilled()) {
            WriteNumberIntoCellItem(table_item, cell->GetNumber());
        } else {
            WritePossibleNumbersIntoCellItem(table_item, cell->GetPossibleNumbers());
        }
    }
}

void SudokuGui::WriteNumberIntoCellItem(QTableWidgetItem *item, const std::size_t number) {
    QColor green{0, 128, 0};
    item->setTextColor(green);
    QFont font{"Times", 24, QFont::Bold};
    item->setFont(font);
    QString string = QString::number(number);
    item->setText(string);
}

void SudokuGui::WritePossibleNumbersIntoCellItem(QTableWidgetItem *item,
                                                 const std::vector<std::size_t> &possible_numbers) {
    QColor gray{128, 128, 128};
    item->setTextColor(gray);

    QString string{};
    for (int number{1}; number < 10; ++number) {
        if (std::find(possible_numbers.begin(), possible_numbers.end(), number) != possible_numbers.end()) {
            string.append(QString::number(number));
        } else {
            string.append(" ");
        }

        if (number == 3 || number == 6) {
            string.append("\n");
        } else {
            string.append("  ");
        }
    }
    item->setText(string);
}
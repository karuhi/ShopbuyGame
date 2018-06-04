#include <iostream>


using namespace std;

void game();
void loading();

// C++のお勉強

namespace EnumX {
    int possession_money = 1000;
    char hr[41] = "- - - - - - - - - - - - - - - -\n";
    char hrf[41] = "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
    int SelectNum = 0;
    int ShopPrice[4] = {100, 200, 300, 400};
    char ShopList[4][40] = {"A店", "B店", "C店", "D店"};
    int BuyList[4] = {0, 0, 0, 0};
}

int main() {
    string a;
    cout << EnumX::hr;
    cout << "あなたの所持金は" << EnumX::possession_money << "円です。" << endl << EnumX::hr;
    cout << "ゲームを始めますか？" << endl << "Yes or No";
    cin >> a;
    while (true) {
        if (a == "Y" || a == "Yes" || a == "yes") {
            loading();
            break;
        } else if (a == "N" || a == "No" || a == "no") {
            cout << "See You!";
            break;
        } else {
            cout << "Typo!!!!!!";
            cin >> a;
        }
    }
    return 0;
}

void loading() {
    cout << "ロード中..." << endl << "ゲーム開始！" << endl;
    game();
}

void checksum(int num) {
    if (EnumX::possession_money < EnumX::ShopPrice[num]){
        cout << endl << "お金が足りません！" << endl;
    }else {
        EnumX::possession_money = (EnumX::possession_money - EnumX::ShopPrice[num]);
        EnumX::SelectNum = num + 1;
        EnumX::BuyList[num] += 1;
        cout << EnumX::ShopList[EnumX::SelectNum-1] << "で、買い物をしました！";
        cout << "所持金-" << EnumX::ShopPrice[EnumX::SelectNum-1] << "円" << endl << endl;
    }
}

void game() {
    if (EnumX::possession_money > 0) {
        string ShopSelect;
        cout << EnumX::hrf << "";
        for (int i = 0; i < 4; i++) {
            cout << EnumX::ShopList[i] << ":" << EnumX::ShopPrice[i] << "円 ";
        }
        cout << endl << EnumX::hrf;
        cout << "どのお店でお買い物をしますか？" << "(残金：" << EnumX::possession_money << "円)";
        cin >> ShopSelect;
        if (ShopSelect == "A" || ShopSelect == "a") {
            checksum(0);
        } else if (ShopSelect == "B" || ShopSelect == "b") {
            checksum(1);
        } else if (ShopSelect == "C" || ShopSelect == "c") {
            checksum(2);
        } else if (ShopSelect == "D" || ShopSelect == "d") {
            checksum(3);
        } else {
            cout << "Typo!!" << endl;
        }

        game();
    } else {
        cout << "ゲーム終了！" << endl << EnumX::hr << "あなたは、";
        for (int i = 0; i < 4; i++) {
            cout << EnumX::ShopList[i] << "で" << EnumX::ShopPrice[i] * EnumX::BuyList[i] << "円 ";
        }
        cout << "購入しました！" << endl << EnumX::hr;
    }
}